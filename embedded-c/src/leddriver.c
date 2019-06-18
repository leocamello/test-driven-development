#include "leddriver.h"

enum { ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~ALL_LEDS_OFF };

static uint16_t ledsImage;
static uint16_t* ledsAddress;

static int ConvertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Initialize(uint16_t* address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    *ledsAddress = ledsImage;
}

void LedDriver_TurnOn(int ledNumber)
{
    ledsImage |= ConvertLedNumberToBit(ledNumber);
    *ledsAddress = ledsImage;
}

void LedDriver_TurnOff(int ledNumber)
{
    ledsImage &= ~ConvertLedNumberToBit(ledNumber);
    *ledsAddress = ledsImage;
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    *ledsAddress = ledsImage;
} 