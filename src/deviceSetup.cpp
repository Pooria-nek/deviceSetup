#include "deviceSetup.h"

deviceSetup::deviceSetup(int pin, int cooldownTime, int holdTime, void (*shortPressCallback)(), void (*longPressCallback)())
{
    _pin = pin;
    _cooldownTime = cooldownTime;
    _holdTime = holdTime;
    _shortPressCallback = shortPressCallback;
    _longPressCallback = longPressCallback;
    _pressStartTime = 0;
    _lastPressTime = 0;
    _isHeld = false;
    pinMode(pin, INPUT); // Initialize the button pin
}

void deviceSetup::readButton()
{
    unsigned long currentTime = millis();

    // If the button is pressed
    if (!digitalRead(_pin))
    {
        // If the button was just pressed, record the start time
        if (_pressStartTime == 0)
        {
            _pressStartTime = currentTime;
        }

        // If the button has been held longer than the hold time
        if ((currentTime - _pressStartTime) >= _holdTime && !_isHeld)
        {
            _longPressCallback(); // Call the long press function
            _isHeld = true;       // Mark button as held to avoid multiple triggers
        }
    }
    else
    {
        // If the button is released
        if (_pressStartTime > 0)
        {
            // If it wasn't held long enough for a long press, trigger short press
            if (!_isHeld && (currentTime - _pressStartTime < _holdTime) && (currentTime - _lastPressTime >= _cooldownTime))
            {
                _shortPressCallback();        // Call the short press function
                _lastPressTime = currentTime; // Reset cooldown
            }
            // Reset variables after button release
            _pressStartTime = 0;
            _isHeld = false;
        }
    }
}