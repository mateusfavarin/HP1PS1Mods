#ifndef LEVEL6MENU_H
#define LEVEL6MENU_H
#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_level6Title = {
    .text = s_level6,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_diagonAlley = {
    .text = s_level6,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_ollivandersWands = {
    .text = s_ollivandersWands,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_eeylopsOwlEmporium = {
    .text = s_eeylopsOwlEmporium,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_magicalMenagerie = {
    .text = s_magicalMenagerie,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_forbbidenForest = {
    .text = s_forbbidenForest,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_voldermortandTheUnicorn = {
    .text = s_voldermortandTheUnicorn,
    .x = 0xAA,
    .y = 0x200
};

CustomText * ct_level6Arr[] = {&ct_diagonAlley, &ct_ollivandersWands, &ct_eeylopsOwlEmporium,
                            &ct_magicalMenagerie, &ct_forbbidenForest, &ct_voldermortandTheUnicorn};
u8 level6_isSelected[] = {0, 0, 0, 0, 0, 0};

extern LevelSelector levelSelector;

void Level6_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 6;
    levelSelector.map = cursor + 1;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level6_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level6 = {
    .title = &ct_level6Title,
    .textArray = ct_level6Arr,
    .isSelected = level6_isSelected,
    .textCount = sizeof(ct_level6Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level6_onSelect,
    .onBack = Level6_onBack
};

#endif