#ifndef GAME_H
#define GAME_H

#include <types.h>

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

extern OptionsManager options;
extern LevelSelector levelSelector;

#endif