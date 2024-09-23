#ifndef deviceSetup_h
#define deviceSetup_h

#include <Arduino.h>

class deviceSetup {
  public:
    // Constructor for button handling
    deviceSetup(int pin, int cooldownTime, int holdTime, void (*shortPressCallback)(), void (*longPressCallback)());

    // Constructor for LED handling
    deviceSetup(int ledPin, bool startState, unsigned long blinkInterval);

    // Function to read button state
    void readButton();
    
    // Functions to control LED state
    void setOn();
    void setOff();
    void setBlink(unsigned long interval);
    void updateLED();

  private:
    int _pin;
    unsigned long _pressStartTime;
    unsigned long _lastPressTime;
    bool _isHeld;
    int _cooldownTime;
    int _holdTime;
    void (*_shortPressCallback)();
    void (*_longPressCallback)();
    
    // LED control variables
    int _ledPin;
    bool _ledState;
    unsigned long _blinkInterval;
    unsigned long _lastBlinkTime;
    bool _isBlinking;
};

#endif