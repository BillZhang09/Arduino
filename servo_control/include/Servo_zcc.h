#pragma once
#include <Arduino.h>
#include <Servo.h>

class Servo_zcc : public Servo
{
    private:
        const uint8_t _pin;
        uint16_t _currentPosition = 90;
        unsigned long _servoMillis = 0;
        unsigned long _currentMillis = 0;
    public:
        Servo_zcc(uint8_t pin);
        void servoAttach();
        void setPosition(uint16_t targetAngle);
        void setPosition(uint16_t targetAngle, uint16_t interval);
};