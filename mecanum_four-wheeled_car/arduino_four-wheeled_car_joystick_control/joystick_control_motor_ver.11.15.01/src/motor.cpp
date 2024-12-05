#include "motor.h"

Motor::Motor(const uint8_t pin_inA, const uint8_t pin_inB, const uint8_t pin_PWM)
    :_pin_inA(pin_inA),_pin_inB(pin_inB),_pin_PWM(pin_PWM){
        pinMode(_pin_inA,OUTPUT);
        pinMode(_pin_inB,OUTPUT);
        pinMode(_pin_PWM,OUTPUT);
        //setSpeed(0);
}


Motor::Motor(const uint8_t pin_inA, const uint8_t pin_inB, const uint8_t pin_PWM, int16_t min_speed, int16_t max_speed)
    :_pin_inA(pin_inA),_pin_inB(pin_inB),_pin_PWM(pin_PWM){
    pinMode(_pin_inA,OUTPUT);
    pinMode(_pin_inB,OUTPUT);
    pinMode(_pin_PWM,OUTPUT);
    _min_speed = min_speed;
    _max_speed = max_speed;
}
                        
void Motor::setSpeed(int16_t speed)
{
    _speed = constrain(speed,_min_speed,_max_speed);
    if(_speed > 0){
        digitalWrite(_pin_inA,HIGH);
        digitalWrite(_pin_inB,LOW);
        analogWrite(_pin_PWM,_speed);
    }else if(_speed < 0){
        digitalWrite(_pin_inA,LOW);
        digitalWrite(_pin_inB,HIGH);
        analogWrite(_pin_PWM,-_speed);
    }else {
        digitalWrite(_pin_inA,LOW);
        digitalWrite(_pin_inB,LOW);
        analogWrite(_pin_PWM,0);
    }
}

int16_t Motor::getSpeed()
{
    Serial.print(_speed);
    return _speed;
}