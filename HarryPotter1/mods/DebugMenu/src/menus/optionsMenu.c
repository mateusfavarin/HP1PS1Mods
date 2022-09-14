#include <types.h>
#include <addresses.h>
#include "game.h"
#include "strings.h"
#include "pause.h"

CustomText ct_optionsMenuTitle = {
    .text = s_options,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_enableSaveStates = {
    .text = s_enableSaveStates,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_showTimer = {
    .text = s_showTimer,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_showLagTimer = {
    .text = s_showLagTimer,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_resetProgresswhenSelectingLevel = {
    .text = s_resetProgresswhenSelectingLevel,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_resetTimerswhenSelectingLevel = {
    .text = s_resetTimerswhenSelectingLevel,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_skipIntroCutscene = {
    .text = s_skipIntroCutscene,
    .x = 0xAA,
    .y = 0x200
};

CustomText ct_enablePausingAnywhere = {
    .text = s_enablePausingAnywhere,
    .x = 0xBC,
    .y = 0x200
};

CustomText * ct_optionsMenuArr[] = {&ct_enableSaveStates, &ct_showTimer, &ct_showLagTimer,
                                    &ct_resetProgresswhenSelectingLevel,
                                    &ct_resetTimerswhenSelectingLevel,
                                    &ct_skipIntroCutscene, &ct_enablePausingAnywhere};

u8 optionsMenu_isSelected[] = {1, 1, 1, 1, 1, 1, 1};

void OptionsMenu_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    menu->isSelected[cursor] ^= 1;
    u32 * optionsArr = (u32 *) &options;
    optionsArr[cursor] ^= 1;
    if (cursor == 5)
    {
        if (optionsArr[cursor])
            ForceStartGameLevel = 1;
        else
            ForceStartGameLevel = 7;
    }
    if (cursor == 6)
    {
        if (optionsArr[cursor])
            ForceUnpause = 0;
        else
            ForceUnpause = 0xAC2075F4;
    }
}

void OptionsMenu_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 0;
}

CustomMenu cm_optionsMenu = {
    .title = &ct_optionsMenuTitle,
    .textArray = ct_optionsMenuArr,
    .isSelected = optionsMenu_isSelected,
    .textCount = sizeof(ct_optionsMenuArr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = OptionsMenu_onSelect,
    .onBack = OptionsMenu_onBack
};