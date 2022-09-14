#include <types.h>
#include <addresses.h>
#include "game.h"
#include "pause.h"
#include "strings.h"

CustomText ct_level4Title = {
    .text = s_level4,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_upperCastleHub = {
    .text = s_level4,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_upperCastle = {
    .text = s_upperCastle,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_voldermortBoss = {
    .text = s_voldermortBoss,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_trollBoss = {
    .text = s_trollBoss,
    .x = 0x86,
    .y = 0x200
};

CustomText ct_fluffy = {
    .text = s_fluffy,
    .x = 0x98,
    .y = 0x200
};

CustomText ct_devilsSnare = {
    .text = s_devilsSnare,
    .x = 0xAA,
    .y = 0x200
};

CustomText ct_theFlyingKeysSection = {
    .text = s_theFlyingKeysSection,
    .x = 0xBC,
    .y = 0x200
};

CustomText ct_chessandPotions = {
    .text = s_chessandPotions,
    .x = 0xCE,
    .y = 0x200
};

CustomText ct_sleepingTrollPotions = {
    .text = s_sleepingTrollPotions,
    .x = 0xE0,
    .y = 0x200
};

CustomText * ct_level4Arr[] = {&ct_upperCastleHub, &ct_upperCastle, &ct_voldermortBoss, &ct_trollBoss,
                                &ct_fluffy, &ct_devilsSnare, &ct_theFlyingKeysSection, &ct_chessandPotions,
                                &ct_sleepingTrollPotions};
u8 level4_isSelected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void Level4_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 4;
    levelSelector.map = cursor + 1;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level4_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level4 = {
    .title = &ct_level4Title,
    .textArray = ct_level4Arr,
    .isSelected = level4_isSelected,
    .textCount = sizeof(ct_level4Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level4_onSelect,
    .onBack = Level4_onBack
};