#include "unity_fixture.h"
#include "leddriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
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
    uint16_t virtualLeds;
    LedDriver_Initialize(&virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
} 

TEST(LedDriver, TurnOffLedOne)
{
    uint16_t virtualLeds;
    LedDriver_Initialize(&virtualLeds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
} 