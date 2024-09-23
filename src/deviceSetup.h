#ifndef deviceSetup_h
#define deviceSetup_h

#include <Arduino.h>

class deviceSetup {
  public:
    enum BuzzerType {
        ACTIVE,
        PASSIVE
    };

    // Constructor for button handling
    deviceSetup(int pin, int cooldownTime, int holdTime, void (*shortPressCallback)(), void (*longPressCallback)());
    
    // Constructor for LED handling
    deviceSetup(int ledPin, bool startState, unsigned long blinkInterval);
    
    // Constructor for Piezo Buzzer with type
    deviceSetup(int buzzerPin, BuzzerType type);

    // Function to read button state
    void readButton();
    
    // Functions to control LED state
    void setOn();
    void setOff();
    void setBlink(unsigned long interval);
    void updateLED();

    // Functions to control Piezo Buzzer
    void playTone(int frequency, unsigned long duration);
    void stopTone();

  private:
    int _pin;                    // For button
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

    // Buzzer control variables
    int _buzzerPin;
    BuzzerType _buzzerType;
};

#endif