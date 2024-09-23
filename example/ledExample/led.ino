#include <deviceSetup.h>

// LED object
deviceSetup led1(PIN_LED_1, false, 500);  // Starts off with a 500ms blink interval

void setup() {
    // Initialize components here
}

void loop() {
    led1.updateLED();  // Continuously update LED blinking state
}

void someFunction() {
    led1.setOn();    // Turn LED on
    led1.setOff();   // Turn LED off
    led1.setBlink(300);  // Set LED to blink with 300ms interval
}