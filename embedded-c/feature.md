# Feature

Use LEDs to communicate status.

## User Story

***As*** a system, \
***I want to*** use LEDs, \
***So that*** I can communicate status.

## Acceptance Criteria

All LEDs are off after the driver is initialized.

``` gherkin
When I initialize the LED driver
Then all LEDs should be off
```

A single LED can be turned on.

``` gherkin
Given the LED driver is initialized
When I turn on LED 01
Then LED 01 should be on
```

A single LED can be turned off.

``` gherkin
Given the LED driver is initialized
And LED 01 is on
When I turn off LED 01
Then LED 01 should be off
```

Multiple LEDs can be turned on/off.

``` gherkin
Given the LED driver is initialized
When I turn on LED 09
And I turn on LED 08
Then LED 09 should be on
And LED 08 should be on
```

Turn on all LEDs.

``` gherkin
Given the LED driver is initialized
When I turn all LEDs on
Then all LEDs should be on
```

Multiple LEDs can be turned on/off.

``` gherkin
Given the LED driver is initialized
And all LEDs are on
When I turn off LED 09
And I turn off LED 08
Then LED 09 should be off
And LED 08 should be off
```