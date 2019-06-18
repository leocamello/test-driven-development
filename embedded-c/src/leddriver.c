#include "leddriver.h"

enum { ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~ALL_LEDS_OFF };

static uint16_t ledsImage;
static uint16_t* ledsAddress;

static void UpdateHardware(void)
{
    *ledsAddress = ledsImage;    
}

static int ConvertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Initialize(uint16_t* address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    UpdateHardware();
}

void LedDriver_TurnOn(int ledNumber)
{
    if (ledNumber <= 0 || ledNumber > 16)
        return;    

    ledsImage |= ConvertLedNumberToBit(ledNumber);
    UpdateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if (ledNumber <= 0 || ledNumber > 16)
        return;    
        
    ledsImage &= ~ConvertLedNumberToBit(ledNumber);
    UpdateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    UpdateHardware();
} 