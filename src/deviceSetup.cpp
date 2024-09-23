#include "deviceSetup.h"

// Constructor for buttons
deviceSetup::deviceSetup(int pin, int cooldownTime, int holdTime, void (*shortPressCallback)(), void (*longPressCallback)()) {
    _pin = pin;
    _cooldownTime = cooldownTime;
    _holdTime = holdTime;
    _shortPressCallback = shortPressCallback;
    _longPressCallback = longPressCallback;
    _pressStartTime = 0;
    _lastPressTime = 0;
    _isHeld = false;
    pinMode(pin, INPUT);  // Initialize the button pin
}

// Constructor for LEDs
deviceSetup::deviceSetup(int ledPin, bool startState, unsigned long blinkInterval) {
    _ledPin = ledPin;
    _ledState = startState;
    _blinkInterval = blinkInterval;
    _lastBlinkTime = 0;
    _isBlinking = false;
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, startState ? HIGH : LOW);  // Set initial LED state
}

// Function to turn LED on
void deviceSetup::setOn() {
    _isBlinking = false;
    _ledState = true;
    digitalWrite(_ledPin, HIGH);
}

// Function to turn LED off
void deviceSetup::setOff() {
    _isBlinking = false;
    _ledState = false;
    digitalWrite(_ledPin, LOW);
}

// Function to set blinking state with interval
void deviceSetup::setBlink(unsigned long interval) {
    _isBlinking = true;
    _blinkInterval = interval;
}

// Function to update LED blinking state
void deviceSetup::updateLED() {
    if (_isBlinking) {
        unsigned long currentTime = millis();
        if (currentTime - _lastBlinkTime >= _blinkInterval) {
            _ledState = !_ledState;
            digitalWrite(_ledPin, _ledState ? HIGH : LOW);
            _lastBlinkTime = currentTime;
        }
    }
}

// Existing button reading function (unchanged)
void deviceSetup::readButton() {
    unsigned long currentTime = millis();
    
    if (!digitalRead(_pin)) {
        if (_pressStartTime == 0) {
            _pressStartTime = currentTime;
        }
        if ((currentTime - _pressStartTime) >= _holdTime && !_isHeld) {
            _longPressCallback();
            _isHeld = true;
        }
    } else {
        if (_pressStartTime > 0) {
            if (!_isHeld && (currentTime - _pressStartTime < _holdTime) && (currentTime - _lastPressTime >= _cooldownTime)) {
                _shortPressCallback();
                _lastPressTime = currentTime;
            }
            _pressStartTime = 0;
            _isHeld = false;
        }
    }
}