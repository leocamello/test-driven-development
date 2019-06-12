#include "unity_fixture.h"
#include "leddriver.h"

TEST_GROUP(LedDriver);

static uint16_t virtualLeds;

TEST_SETUP(LedDriver)
{
    LedDriver_Initialize(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{
}

TEST(LedDriver, LedsOffAfterInitialize)
{
    uint16_t virtualLeds = 0xFFFF;
    LedDriver_Initialize(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
} 

TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
} 

TEST(LedDriver, TurnOffLedOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
} 

TEST(LedDriver, TurnOnMultipleLeds)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x0180, virtualLeds);
} 

TEST(LedDriver, TurnAllLedsOn)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
} 