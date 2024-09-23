#include <deviceSetup.h>

// Button and LED objects
deviceSetup led1(PIN_LED_1, false, 500);  // LED 1 starts off with a 500ms blink interval

void setup() {
    // Initialize components
}

void loop() {
    // Continuously update LED state
    led1.updateLED();
}