#include <deviceSetup.h>

// Declare callback functions for Button 1
void onButton1ShortPress();
void onButton1LongPress();

// Declare callback functions for Button 2
void onButton2ShortPress();
void onButton2LongPress();

// Create deviceSetup objects for the buttons after function declarations
deviceSetup button1(PIN_BUTTON_1, 1000, 2000, onButton1ShortPress, onButton1LongPress);
deviceSetup button2(PIN_BUTTON_2, 1000, 2000, onButton2ShortPress, onButton2LongPress);

void setup() {
    // Any necessary setup code
}

void loop() {
    // Continuously check the state of each button
    button1.readButton();
    button2.readButton();
}

// Define the callback functions for Button 1
void onButton1ShortPress() {
    // Action for Button 1 short press
}

void onButton1LongPress() {
    // Action for Button 1 long press
}

// Define the callback functions for Button 2
void onButton2ShortPress() {
    // Action for Button 2 short press
}

void onButton2LongPress() {
    // Action for Button 2 long press
}