#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

void DrawLoadingBar();
void FCOpen(s8 * filename);
void FCRead(u8 * buffer, u32 bytes);
void ResetProgress(u32 param_1, u32 param_2);
void LevelSwitch();
void InitGame();
void ProcessStrategies();
void DrawText(u16 * text, u32 x, u8 r, u8 g, u8 b, u32 y);
void SFX_Set(u32 distortion, u32 sfxID, u32 * sfx);
void SFX_Play(u32 param_1, u32 * sfx);
void StartFrame();
void HandlePause();
u32 * ReadWad(u8 tribeIndex, u8 levelIndex, u8 mapIndex, u8 levelType);

#endif