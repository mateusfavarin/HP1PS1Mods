#ifndef PAUSE_H
#define PAUSE_H

enum Buttons {
    SELECT = 0x1,
    L3 = 0x2,
    R3 = 0x4,
    START = 0x8,
    UP = 0x10,
    RIGHT = 0x20,
    DOWN = 0x40,
    LEFT = 0x80,
    L2 = 0x100,
    R2 = 0x200,
    L1 = 0x400,
    R1 = 0x800,
    TRIANGLE = 0x1000,
    CIRCLE = 0x2000,
    CROSS = 0x4000,
    SQUARE = 0x8000
};

typedef struct {
    u32 * PlayerSaveState;
    u32 * CameraSaveState;
    u32 hasSaved;
} SaveStateManager;

typedef struct {
    u8 tribe;
    u8 level;
    u8 map;
    u8 levelType;
    u32 loadLevel;
} LevelSelector;

typedef struct {
    u32 enableSaveStates;
    u32 showTimer;
    u32 showLagTimer;
    u32 resetProgress;
    u32 resetTimers;
    u32 skipIntro;
    u32 enablePausing;
} OptionsManager;

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
void PlayPauseSFX();
void PlayCursorSFX();
void HandleCustomPause();

#endif