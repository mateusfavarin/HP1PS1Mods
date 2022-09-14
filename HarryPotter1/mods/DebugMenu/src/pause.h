#ifndef PAUSE_H
#define PAUSE_H

typedef struct {
    u8 * text;
    u32 x;
    u32 y;
} CustomText;

typedef struct {
    CustomText * title;
    CustomText ** textArray;
    u8 * isSelected;
    u32 textCount;
    u32 cursor;
    void (* onSelect)(void *);
    void (* onBack)(void *);
} CustomMenu;

typedef struct {
    CustomMenu ** menuArray;
    u32 currentMenu;
} CustomPause;

void Pause();
void Unpause();
void HandleCustomPause();

extern CustomMenu cm_debugMenu;
extern CustomMenu cm_cheatMenu;
extern CustomMenu cm_selectLevel;
extern CustomMenu cm_optionsMenu;
extern CustomMenu cm_level1;
extern CustomMenu cm_level2;
extern CustomMenu cm_level3;
extern CustomMenu cm_level4;
extern CustomMenu cm_level6;
extern CustomMenu cm_level7;
extern CustomMenu cm_level8;
extern CustomMenu cm_level9;

#endif