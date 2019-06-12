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