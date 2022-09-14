#ifndef TIMER_H
#define TIMER_H

#include <types.h>
#define FRAME 16
#define SECOND (FRAME * 60)
#define MINUTE 60

typedef struct {
    u32 ms;
    u32 seconds;
    u32 minutes;
    u32 maxTimer;
    s32 currVBlank;
    u32 isLagTimer;
    u32 x;
    u32 y;
    u8 r;
    u8 b;
    u8 g;
} Timer;

void ResetTimerString(u8 * timerString);
void ResetTimer(Timer * timer);
void AdvanceTimer(Timer * timer);
void DrawTimer(Timer * timer);

#endif