#ifndef LEVEL1MENU_H
#define LEVEL1MENU_H
#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_level1Title = {
    .text = s_level1,
    .x = 0x20,
    .y = 0x200
};

CustomText ct_credits = {
    .text = s_credits,
    .x = 0x40,
    .y = 0x200
};

CustomText ct_castleHub = {
    .text = s_level1,
    .x = 0x52,
    .y = 0x200
};

CustomText ct_rescueHedwig = {
    .text = s_rescueHedwig,
    .x = 0x64,
    .y = 0x200
};

CustomText ct_broomstickTraining = {
    .text = s_broomstickTraining,
    .x = 0x76,
    .y = 0x200
};

CustomText ct_charmsClass = {
    .text = s_charmsClass,
    .x = 0x88,
    .y = 0x200
};

CustomText ct_hpDoor = {
    .text = s_hpDoor,
    .x = 0x9A,
    .y = 0x200
};

CustomText ct_crabbeandGoyle = {
    .text = s_crabbeandGoyle,
    .x = 0xAC,
    .y = 0x200
};

CustomText ct_storytellerRoom = {
    .text = s_storytellerRoom,
    .x = 0xBE,
    .y = 0x200
};

CustomText ct_rescueHedwig2 = {
    .text = s_rescueHedwig2,
    .x = 0xD0,
    .y = 0x200
};

CustomText ct_commonRoom = {
    .text = s_commonRoom,
    .x = 0xE2,
    .y = 0x200
};

CustomText * ct_level1Arr[] = {&ct_credits, &ct_castleHub, &ct_rescueHedwig, &ct_broomstickTraining,
                                &ct_charmsClass, &ct_hpDoor, &ct_crabbeandGoyle, &ct_storytellerRoom,
                                &ct_rescueHedwig2, &ct_commonRoom};
u8 level1_isSelected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

extern LevelSelector levelSelector;

void Level1_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 1;
    levelSelector.map = cursor;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level1_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level1 = {
    .title = &ct_level1Title,
    .textArray = ct_level1Arr,
    .isSelected = level1_isSelected,
    .textCount = sizeof(ct_level1Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level1_onSelect,
    .onBack = Level1_onBack
};

#endif