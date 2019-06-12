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