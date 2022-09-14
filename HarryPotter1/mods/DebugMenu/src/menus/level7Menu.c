#include <types.h>
#include <addresses.h>
#include "game.h"
#include "pause.h"
#include "strings.h"

CustomText ct_level7Title = {
    .text = s_level7,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_gringottsBank = {
    .text = s_level7,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_mineCartKnut = {
    .text = s_mineCartKnut,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_mineCartSickle = {
    .text = s_mineCartSickle,
    .x = 0x74,
    .y = 0x200
};

CustomText ct_mineCartGalleon = {
    .text = s_mineCartGalleon,
    .x = 0x86,
    .y = 0x200
};

CustomText * ct_level7Arr[] = {&ct_gringottsBank, &ct_mineCartKnut, &ct_mineCartSickle,
                            &ct_mineCartGalleon};
u8 level7_isSelected[] = {0, 0, 0, 0};

void Level7_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    levelSelector.loadLevel = 1;
    levelSelector.level = 7;
    levelSelector.map = cursor + 1;
    ForceLoadLevel = 0x10;
    Unpause();
}

void Level7_onBack(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    customPauseMenu->currentMenu = 2;
}

CustomMenu cm_level7 = {
    .title = &ct_level7Title,
    .textArray = ct_level7Arr,
    .isSelected = level7_isSelected,
    .textCount = sizeof(ct_level7Arr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = Level7_onSelect,
    .onBack = Level7_onBack
};