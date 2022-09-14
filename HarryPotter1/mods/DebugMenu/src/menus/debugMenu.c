#include <types.h>
#include "pause.h"
#include "strings.h"

CustomText ct_debugMenu = {
    .text = s_debugMenu,
    .x = 0x30,
    .y = 0x200
};

CustomText ct_toggleCheats = {
    .text = s_toggleCheats,
    .x = 0x50,
    .y = 0x200
};

CustomText ct_selectLevel = {
    .text = s_selectLevel,
    .x = 0x62,
    .y = 0x200
};

CustomText ct_options = {
    .text = s_options,
    .x = 0x74,
    .y = 0x200
};

CustomText * ct_debugMenuArr[] = {&ct_toggleCheats, &ct_selectLevel, &ct_options};
u8 debugMenu_isSelected[] = {0, 0, 0};

void DebugMenu_onSelect(void * pauseMenu)
{
    CustomPause * customPauseMenu = (CustomPause *) pauseMenu;
    CustomMenu * menu = customPauseMenu->menuArray[customPauseMenu->currentMenu];
    u32 cursor = menu->cursor;
    customPauseMenu->currentMenu = cursor + 1;
}

CustomMenu cm_debugMenu = {
    .title = &ct_debugMenu,
    .textArray = ct_debugMenuArr,
    .isSelected = debugMenu_isSelected,
    .textCount = sizeof(ct_debugMenuArr) / sizeof(CustomText *),
    .cursor = 0,
    .onSelect = DebugMenu_onSelect,
};