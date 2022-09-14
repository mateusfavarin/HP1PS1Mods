#include <types.h>
#include <functions.h>
#include <addresses.h>

void Hook_InitGame()
{
    InitGame();
    FCOpen("DUTCH.BIN");
    FCRead((u8 *) 0x8000E500, 0x1900); // Loading our custom assembly
    FCOpen("DANISH.BIN");
    FCRead((u8 *) 0x8000A000, 0x1900); // Loading our custom strings
    ForceStartGameLevel = 1; // Skip first story book
    ForceUnpause = 0; // You can pause at anytime
}