#ifndef LEVEL8MENU_H
#define LEVEL8MENU_H
#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_level8Title = {
    .text = s_level8,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_dungeonSecret = {
    .text = s_level8,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_secretBulbOutdoorSection = {
    .text = s_secretBulbOutdoorSection,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_tuckShopSecret = {
    .text = s_tuckShopSecret,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_trollBoss2 = {
    .text = s_trollBoss2,
    .x = 0x86,
    .y = 0x200
};

CustomText * ct_level8Arr[] = {&ct_dungeonSecret, &ct_secretBulbOutdoorSection, &ct_tuckShopSecret,
                            &ct_trollBoss2};
u8 level8_isSelected[] = {0, 0, 0, 0};

extern LevelSelector levelSelector;

void Level8_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 8;
    levelSelector.map = cursor + 1;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level8_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level8 = {
    .title = &ct_level8Title,
    .textArray = ct_level8Arr,
    .isSelected = level8_isSelected,
    .textCount = sizeof(ct_level8Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level8_onSelect,
    .onBack = Level8_onBack
};

#endif