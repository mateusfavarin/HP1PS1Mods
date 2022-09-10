#ifndef SELECTLEVELMENU_H
#define SELECTLEVELMENU_H
#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_selectLevelTitle = {
    .text = s_selectLevel,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_level1 = {
    .text = s_level1,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_level2 = {
    .text = s_level2,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_level3 = {
    .text = s_level3,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_level4 = {
    .text = s_level4,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_level6 = {
    .text = s_level6,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_level7 = {
    .text = s_level7,
    .x = 0xAA,
    .y = 0x200
};

CustomText ct_level8 = {
    .text = s_level8,
    .x = 0xBC,
    .y = 0x200
};

CustomText ct_level9 = {
    .text = s_level9,
    .x = 0xCE,
    .y = 0x200
};

CustomText * ct_selectLevelArr[] = {&ct_level1, &ct_level2, &ct_level3, &ct_level4,
                                &ct_level6, &ct_level7, &ct_level8, &ct_level9};
u8 selectLevel_isSelected[] = {0, 0, 0, 0, 0, 0, 0, 0};

void SelectLevel_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    customPauseMenu->currentMenu = cursor + 4;
}

void SelectLevel_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 0;
}

CustomMenu cm_selectLevel = {
    .title = &ct_selectLevelTitle,
    .textArray = ct_selectLevelArr,
    .isSelected = selectLevel_isSelected,
    .textCount = sizeof(ct_selectLevelArr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = SelectLevel_onSelect,
    .onBack = SelectLevel_onBack
};

#endif