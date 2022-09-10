#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "types.h"

extern s32 Paused;
extern u32 CheatFlags;
extern u32 GameState;
extern u16 ButtonsTapped;
extern u16 ButtonsHeld;
extern u8 SkipDrawIcons;
extern u8 ForceLoadLevel;
extern u8 ForceStartGameLevel;
extern s32 VBlank_Last;
extern u32 CurrentSFX[];
extern u32 SFX_unk1;
extern u16 SFX_unk2;
extern u32 SFX_unk3;
extern u16 NoCollision_1;
extern u16 NoCollision_2;
extern u16 NoCollision_3;
extern s32 PlayerHorSpeed;
extern s32 PlayerVerSpeed;
extern u32 * PlayerStrat;
extern u32 * CameraStrat;
extern u32 ForceUnpause;

#endif