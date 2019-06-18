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

TEST(LedDriver, TurnOffMultipleLeds)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(9);
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xFE7F, virtualLeds);
} 

TEST(LedDriver, LedMemoryIsNotReadable)
{
    virtualLeds = 0xFFFF;
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x0080, virtualLeds);
} 

TEST(LedDriver, UpperAndLowerBoundaries)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
} 

TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(3141);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
} 

TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(3141);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
} 