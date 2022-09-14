#include <types.h>
#include <functions.h>
#include <addresses.h>
#include "game.h"
#include "pause.h"
#include "strings.h"

CustomMenu * menus[] = {&cm_debugMenu, &cm_cheatMenu, &cm_selectLevel, &cm_optionsMenu,
                        &cm_level1, &cm_level2, &cm_level3, &cm_level4, &cm_level6,
                        &cm_level7, &cm_level8, &cm_level9};

CustomPause customPause = {
    .menuArray = menus,
    .currentMenu = 0
};

void StopSFX()
{
    SFX_unk1 = 9;
    SFX_unk2 = 0xFFFF;
    SFX_unk3 = 0x7F;
}

void PlayPauseSFX()
{
    StopSFX();
    SFX_Set(0, 1, CurrentSFX);
    SFX_Play(0, CurrentSFX);
}

void PlayCursorSFX()
{
    StopSFX();
    SFX_Set(0, 0, CurrentSFX);
    SFX_Play(0, CurrentSFX);
}

void Pause()
{
    Paused = -1;
    SkipDrawIcons = 1;
    PlayPauseSFX();
}

void Unpause()
{
    Paused = 0;
    SkipDrawIcons = 0;
    PlayPauseSFX();
}

void HandleCustomPause()
{
    if (ButtonsTapped & SELECT)
    {
        Unpause();
        return;
    }

    CustomMenu * menu = customPause.menuArray[customPause.currentMenu];
    u32 maxCursor = menu->textCount - 1;

    // Draw Credits/Footer
    if (customPause.currentMenu == 0)
    {
        DrawText((u16 *) s_footer1, 0xDE, 0x80, 0x80, 0x80, 0x200);
        DrawText((u16 *) s_footer2, 0xEC, 0x80, 0x80, 0x80, 0x200);
    }

    if ((ButtonsTapped & CIRCLE) || (ButtonsTapped & TRIANGLE))
    {
        if (customPause.currentMenu == 0)
        {
            Unpause();
            return;
        }
        menu->onBack((void *) &customPause);
        PlayPauseSFX();
        return;
    }

    if (ButtonsTapped & UP)
    {
        if (menu->cursor == 0)
            menu->cursor = maxCursor;
        else
            menu->cursor--;
        PlayCursorSFX();
    }

    if (ButtonsTapped & DOWN)
    {
        menu->cursor++;
        if (menu->cursor > maxCursor)
            menu->cursor = 0;
        PlayCursorSFX();
    }

    if (ButtonsTapped & CROSS)
    {
        menu->onSelect((void *) &customPause);
        PlayPauseSFX();
    }

    CustomText * titleText = menu->title;
    DrawText((u16 *) titleText->text, titleText->x, 0x80, 0x80, 0x80, titleText->y);
    for (u32 i = 0; i < menu->textCount; i++)
    {
        CustomText * customText = menu->textArray[i];
        u8 color = 0x50;
        u8 red = color;
        if (menu->isSelected[i])
            red = 0;
        if (i == menu->cursor)
        {
            color += 0x3C;
            red += 0x3C;
        }
        DrawText((u16 *) customText->text, customText->x, red, color, color, customText->y);
    }
}