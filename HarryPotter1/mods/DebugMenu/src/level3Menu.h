#ifndef LEVEL3MENU_H
#define LEVEL3MENU_H
#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_level3Title = {
    .text = s_level3,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_dungeonHub = {
    .text = s_level3,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_4RoomPuzzle = {
    .text = s_4RoomPuzzle,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_trolls = {
    .text = s_trolls,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_dadaClassroom = {
    .text = s_dadaClassroom,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_quidditchTraining = {
    .text = s_quidditchTraining,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_theGreatHall = {
    .text = s_theGreatHall,
    .x = 0xAA,
    .y = 0x200
};

CustomText * ct_level3Arr[] = {&ct_dungeonHub, &ct_4RoomPuzzle, &ct_trolls, &ct_dadaClassroom,
                                &ct_quidditchTraining, &ct_theGreatHall};
u8 level3_isSelected[] = {0, 0, 0, 0, 0, 0};

extern LevelSelector levelSelector;

void Level3_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 3;
    levelSelector.map = cursor + 1;
    if (levelSelector.map == 6)
        levelSelector.map = 8;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level3_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level3 = {
    .title = &ct_level3Title,
    .textArray = ct_level3Arr,
    .isSelected = level3_isSelected,
    .textCount = sizeof(ct_level3Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level3_onSelect,
    .onBack = Level3_onBack
};

#endif