#include <types.h>
#include <functions.h>
#include <addresses.h>
#include "timer.h"

u8 s_timer[] = {'0', 0x0, '0', 0x0, ':', 0x0, '0', 0x0, '0', 0x0, '.', 0x0, '0', 0x0, '0', 0x0, 0x0, 0x0};
u8 s_lagTimer[] = {'L', 0x0, 'a' - 0x1, 0x0, 'g' - 0x1, 0x0, ':', 0x0, ' ', 0x0, '0', 0x0, '0', 0x0, ':', 0x0, '0', 0x0, '0', 0x0, '.', 0x0, '0', 0x0, '0', 0x0, 0x0, 0x0};
u8 s_maxTimer[] = {'5', 0x0, '9', 0x0, ':', 0x0, '5', 0x0, '9', 0x0, '.', 0x0, '9', 0x0, '9', 0x0, 0x0, 0x0};
u8 s_maxLagTimer[] = {'L', 0x0, 'a' - 0x1, 0x0, 'g' - 0x1, 0x0, ':', 0x0, ' ', 0x0, '5', 0x0, '9', 0x0, ':', 0x0, '5', 0x0, '9', 0x0, '.', 0x0, '9', 0x0, '9', 0x0, 0x0, 0x0};

void ResetTimerString(u8 * timerString)
{
    timerString[0] = '0';
    timerString[2] = '0';
    timerString[6] = '0';
    timerString[8] = '0';
    timerString[12] = '0';
    timerString[14] = '0';
}

void ResetTimer(Timer * timer)
{
    timer->ms = 0;
    timer->seconds = 0;
    timer->minutes = 0;
    timer->maxTimer = 0;
    timer->currVBlank = -1;
    if (timer->isLagTimer)
        ResetTimerString(&s_lagTimer[10]);
    else
        ResetTimerString(s_timer);
}

void AdvanceTimerObject(Timer * timer, u8 * timerString, s32 delta)
{
    timer->ms += delta * FRAME;
    if (timer->ms >= SECOND)
    {
        timer->ms -= SECOND;
        timer->seconds += 1;
        if (timer->seconds == MINUTE)
        {
            timer->seconds -= MINUTE;
            timer->minutes += 1;
            if (timer->minutes > 59)
                timer->maxTimer = 1;
            timerString[0] = '0' + (timer->minutes / 10);
            timerString[2] = '0' + (timer->minutes % 10);
        }
        timerString[6] = '0' + (timer->seconds / 10);
        timerString[8] = '0' + (timer->seconds % 10);
    }
    u32 decimals = ((timer->ms * 1000) / SECOND) / 10;
    timerString[12] = '0' + (decimals / 10);
    timerString[14] = '0' + (decimals % 10);
}

void AdvanceTimer(Timer * timer)
{
    if (timer->currVBlank == -1)
    {
        timer->currVBlank = VBlank_Last;
        return;
    }

    if (timer->maxTimer)
        return;

    s32 VBlank_Delta = VBlank_Last - timer->currVBlank;
    timer->currVBlank = VBlank_Last;
    if (timer->isLagTimer)
    {
        if (VBlank_Delta > 2)
            AdvanceTimerObject(timer, &s_lagTimer[10], VBlank_Delta - 2);
    }
    else
        AdvanceTimerObject(timer, s_timer, VBlank_Delta);
}

void DrawTimer(Timer * timer)
{
    if (timer->isLagTimer)
    {
        if (timer->maxTimer)
            DrawText((u16 *) s_maxLagTimer, timer->x, timer->r, timer->b, timer->g, timer->y);
        else
            DrawText((u16 *) s_lagTimer, timer->x, timer->r, timer->b, timer->g, timer->y);
    }
    else
    {
        if (timer->maxTimer)
            DrawText((u16 *) s_maxTimer, timer->x, timer->r, timer->b, timer->g, timer->y);
        else
            DrawText((u16 *) s_timer, timer->x, timer->r, timer->b, timer->g, timer->y);
    }
}