#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, LedsOffAfterInitialize);
    RUN_TEST_CASE(LedDriver, TurnOnLedOne);
    RUN_TEST_CASE(LedDriver, TurnOffLedOne);
    RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
}