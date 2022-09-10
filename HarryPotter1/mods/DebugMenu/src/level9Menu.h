#ifndef LEVEL9MENU_H
#define LEVEL9MENU_H
#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_level9Title = {
    .text = s_level9,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_hufflepuff = {
    .text = s_hufflepuff,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_ravenclaw = {
    .text = s_ravenclaw,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_slytherin = {
    .text = s_slytherin,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_hufflepuff2 = {
    .text = s_hufflepuff2,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_ravenclaw2 = {
    .text = s_ravenclaw2,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_slytherin2 = {
    .text = s_slytherin2,
    .x = 0xAA,
    .y = 0x200
};

CustomText * ct_level9Arr[] = {&ct_hufflepuff, &ct_ravenclaw, &ct_slytherin, &ct_hufflepuff2,
                                &ct_ravenclaw2, &ct_slytherin2};
u8 level9_isSelected[] = {0, 0, 0, 0, 0, 0};

extern LevelSelector levelSelector;

void Level9_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 9;
    levelSelector.map = cursor + 1;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level9_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level9 = {
    .title = &ct_level9Title,
    .textArray = ct_level9Arr,
    .isSelected = level9_isSelected,
    .textCount = sizeof(ct_level9Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level9_onSelect,
    .onBack = Level9_onBack
};

#endif