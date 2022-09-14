#include <types.h>
#include <addresses.h>
#include "game.h"
#include "pause.h"
#include "strings.h"

CustomText ct_level2Title = {
    .text = s_level2,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_castleGroundsHub = {
    .text = s_level2,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_castleGroundsExtra = {
    .text = s_castleGroundsExtra,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_gargoyle = {
    .text = s_gargoyle,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_hagridsHut = {
    .text = s_hagridsHut,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_broomstickChase = {
    .text = s_broomstickChase,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_fireSeeds = {
    .text = s_fireSeeds,
    .x = 0xAA,
    .y = 0x200
};

CustomText ct_quidditch1 = {
    .text = s_quidditch1,
    .x = 0xBC,
    .y = 0x200
};

CustomText ct_quidditch2 = {
    .text = s_quidditch2,
    .x = 0xCE,
    .y = 0x200
};

CustomText ct_quidditch3 = {
    .text = s_quidditch3,
    .x = 0xE0,
    .y = 0x200
};

CustomText * ct_level2Arr[] = {&ct_castleGroundsHub, &ct_castleGroundsExtra, &ct_gargoyle, &ct_hagridsHut,
                                &ct_broomstickChase, &ct_fireSeeds, &ct_quidditch1, &ct_quidditch2,
                                &ct_quidditch3};
u8 level2_isSelected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void Level2_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 2;
    levelSelector.map = cursor + 1;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level2_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level2 = {
    .title = &ct_level2Title,
    .textArray = ct_level2Arr,
    .isSelected = level2_isSelected,
    .textCount = sizeof(ct_level2Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level2_onSelect,
    .onBack = Level2_onBack
};