#include "leddriver.h"

enum { ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~ALL_LEDS_OFF };

static uint16_t* ledsAddress;

static int ConvertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Initialize(uint16_t* address)
{
    ledsAddress = address;
    *ledsAddress = ALL_LEDS_OFF;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= ConvertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress = 0;
}

void LedDriver_TurnAllOn(void)
{
    *ledsAddress = ALL_LEDS_ON;
} 