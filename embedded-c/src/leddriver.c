#include "leddriver.h"

static uint16_t* ledsAddress;

static int ConvertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Initialize(uint16_t* address)
{
    ledsAddress = address;
    *ledsAddress = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= ConvertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress = 0;
}