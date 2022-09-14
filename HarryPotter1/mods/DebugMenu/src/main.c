#include <types.h>
#include <functions.h>
#include <addresses.h>
#include "game.h"
#include "pause.h"
#include "timer.h"
#define STRAT_SIZE 0x5B
#define STRAT_KERNEL_MEM 0x8000F500

LevelSelector levelSelector = {
    .tribe = 1,
    .level = 1,
    .map = 1,
    .levelType = 0,
    .loadLevel = 0,
};

SaveStateManager states = {
    .PlayerSaveState = (u32 *) STRAT_KERNEL_MEM,
    .CameraSaveState = (u32 *) (STRAT_KERNEL_MEM + (STRAT_SIZE * 4)),
    .hasSaved = 0,
};

Timer timer = {
    .ms = 0,
    .seconds = 0,
    .minutes = 0,
    .maxTimer = 0,
    .currVBlank = -1,
    .isLagTimer = 0,
    .x = 0x15,
    .y = 0x200,
    .r = 0x80,
    .b = 0x80,
    .g = 0x80
};

Timer lagTimer = {
    .ms = 0,
    .seconds = 0,
    .minutes = 0,
    .maxTimer = 0,
    .currVBlank = -1,
    .isLagTimer = 1,
    .x = 0x15,
    .y = 0x380,
    .r = 0xFF,
    .b = 0x15,
    .g = 0x15
};

OptionsManager options = {
    .enableSaveStates = 1,
    .showTimer = 1,
    .showLagTimer = 1,
    .resetProgress = 1,
    .resetTimers = 1,
    .skipIntro = 1,
    .enablePausing = 1
};

u32 resetTimer = 0;

u32 * Hook_ReadWad(u8 tribeIndex, u8 levelIndex, u8 mapIndex, u8 levelType)
{
    states.hasSaved = 0;
    timer.currVBlank = -1;
    lagTimer.currVBlank = -1;
    if (levelSelector.loadLevel)
    {
        levelSelector.loadLevel = 0;
        if (options.resetProgress)
            ResetProgress(0x100, 0);
        if (options.resetTimers)
            resetTimer = 1;
        return ReadWad(levelSelector.tribe, levelSelector.level, levelSelector.map, levelSelector.levelType);
    }

    return ReadWad(tribeIndex, levelIndex, mapIndex, levelType);
}

void Hook_LevelSwitch()
{
    LevelSwitch();
    ForceLoadLevel = 0x14;
}

void Hook_DrawLoadingBar()
{
    DrawLoadingBar();
    DrawTimer(&timer);
    DrawTimer(&lagTimer);
}

void HandleSaveStates()
{
    if (options.enableSaveStates)
    {
        if (ButtonsTapped & CIRCLE)
        {
            for (u32 i = 0; i < STRAT_SIZE; i++)
            {
                states.PlayerSaveState[i] = PlayerStrat[i];
                states.CameraSaveState[i] = CameraStrat[i];
            }
            states.hasSaved = 1;
        }
        else
        {
            if ((states.hasSaved) && ((ButtonsHeld & (CROSS | SQUARE)) == (CROSS | SQUARE)))
            {
                ButtonsHeld &= ~(CROSS | SQUARE);
                for (u32 i = 0; i < STRAT_SIZE; i++)
                {
                    PlayerStrat[i] = states.PlayerSaveState[i];
                    CameraStrat[i] = states.CameraSaveState[i];
                }
            }
        }
    }
}

void Hook_StartFrame()
{
    if (resetTimer)
    {
        resetTimer = 0;
        ResetTimer(&timer);
        ResetTimer(&lagTimer);
    }
    StartFrame();
    HandleSaveStates();
    if ((Paused == -1) && (ButtonsTapped & START))
    {
        Unpause();
        ButtonsTapped &= ~START;
    }
    if ((Paused == 0) && (ButtonsTapped & SELECT))
    {
        Pause();
        ButtonsTapped &= ~SELECT;
    }
    if (options.showTimer)
    {
        if (GameState == 3)
            AdvanceTimer(&timer);
        else
            ResetTimer(&timer);
        DrawTimer(&timer);
    }
    else
    {
        timer.currVBlank = VBlank_Last;
    }
    if (options.showLagTimer)
    {
        if (GameState == 3)
            AdvanceTimer(&lagTimer);
        else
            ResetTimer(&lagTimer);
        DrawTimer(&lagTimer);
    }
    else
    {
        lagTimer.currVBlank = VBlank_Last;
    }
}

void Hook_HandlePause()
{
    if (Paused == -1)
    {
        HandleCustomPause();
        return;
    }
    HandlePause();
    return;
}