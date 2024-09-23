#include <deviceSetup.h>

// Button objects
deviceSetup button1(PIN_BUTTON_1, 1000, 2000, onButton1ShortPress, onButton1LongPress);
deviceSetup button2(PIN_BUTTON_2, 1000, 2000, onButton2ShortPress, onButton2LongPress);

void setup() {
    // Initialize any additional components here
}

void loop() {
    button1.readButton();
    button2.readButton();
}

// Callback functions for Button 1
void onButton1ShortPress() {
    Serial.println("Button 1 short press detected");
}

void onButton1LongPress() {
    Serial.println("Button 1 long press detected");
}

// Callback functions for Button 2
void onButton2ShortPress() {
    Serial.println("Button 2 short press detected");
}

void onButton2LongPress() {
    Serial.println("Button 2 long press detected");
}