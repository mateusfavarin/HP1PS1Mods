#ifndef CHEATMENU_H
#define CHEATMENU_H
#include <types.h>
#include <addresses.h>
#include "pause.h"
#include "strings.h"
#define IN_GAME_CHEAT_COUNT 5

CustomText ct_toggleCheatsTitle = {
    .text = s_toggleCheats,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_invincibility = {
    .text = s_invincibility,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_unlockQuidditch = {
    .text = s_unlockQuidditch,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_allWizardCards = {
    .text = s_allWizardCards,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_flipendoDuo = {
    .text = s_flipendoDuo,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_blurryMode = {
    .text = s_blurryMode,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_superspeed = {
    .text = s_superspeed,
    .x = 0xAA,
    .y = 0x200
};

CustomText ct_flying = {
    .text = s_flying,
    .x = 0xBC,
    .y = 0x200
};

CustomText ct_collisionOff = {
    .text = s_collisionOff,
    .x = 0xCE,
    .y = 0x200
};

CustomText * ct_toggleCheatsArr[] = {&ct_invincibility, &ct_unlockQuidditch, &ct_allWizardCards,
                                    &ct_flipendoDuo, &ct_blurryMode, &ct_superspeed, &ct_flying,
                                    &ct_collisionOff};

u8 toggleCheats_isSelected[] = {0, 0, 0, 0, 0, 0, 0, 0};
u32 customCheats[] = {0, 0, 0};

void ToggleCheats_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    menu->isSelected[cursor] ^= 1;
    if (cursor < IN_GAME_CHEAT_COUNT)
    {
        if (menu->isSelected[cursor])
            CheatFlags |= 1 << cursor;
        else
            CheatFlags &= ~(1 << cursor);
    }
    else
    {
        customCheats[cursor - IN_GAME_CHEAT_COUNT] ^= 1;
    }
}

void ToggleCheats_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 0;
}

void Hook_ProcessStrategies()
{
    ProcessStrategies();
    if ((customCheats[0]) && (ButtonsHeld & R1))
    {
        PlayerHorSpeed = 0x1FF;
    }
    if ((customCheats[1]) && (ButtonsHeld & L1))
    {
        if (PlayerStrat[40] & 2)    // this flag seems to track whether you jumped or not
            PlayerStrat[14] += 500; // y pos += 500
        PlayerVerSpeed = 130;
    }
    if ((customCheats[2]) && ((ButtonsHeld & (L2 | R2)) == (L2 | R2)))
    {
        NoCollision_1 = 0x1000;
        NoCollision_2 = 0x1000;
        NoCollision_3 = 0x1000;
    } else
    {
        NoCollision_1 = 0x1462;
        NoCollision_2 = 0x1040;
        NoCollision_3 = 0x1220;
    }
}

CustomMenu cm_cheatMenu = {
    .title = &ct_toggleCheatsTitle,
    .textArray = ct_toggleCheatsArr,
    .isSelected = toggleCheats_isSelected,
    .textCount = sizeof(ct_toggleCheatsArr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = ToggleCheats_onSelect,
    .onBack = ToggleCheats_onBack
};

#endif