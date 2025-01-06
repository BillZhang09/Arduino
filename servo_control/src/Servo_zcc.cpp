#include "Servo_zcc.h"

Servo_zcc :: Servo_zcc(const uint8_t pin) : _pin(pin) {}

void Servo_zcc :: servoAttach()
{
    attach(_pin);
}

void Servo_zcc :: setPosition(uint16_t targetAngle)
{
    write(targetAngle);
}

void Servo_zcc :: setPosition(uint16_t targetAngle, uint16_t interval)
{
    while(_currentPosition != targetAngle){
        _currentMillis = millis();
        if(_currentMillis - _servoMillis >= interval){
            _servoMillis = _currentMillis;
            if(_currentPosition > targetAngle){
                write(--_currentPosition);//?
                Serial.print(_currentPosition);
            }else{
                write(++_currentPosition);//?
                Serial.print(_currentPosition);
            }
        }
    }
}
