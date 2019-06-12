#include "leddriver.h"

static uint16_t* ledsAddress;

void LedDriver_Initialize(uint16_t* address)
{
    ledsAddress = address;
    *ledsAddress = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress = 1;
}