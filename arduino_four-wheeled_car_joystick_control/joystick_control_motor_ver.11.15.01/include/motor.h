#pragma once
#include <Arduino.h>

class Motor
{
    private:
        const uint8_t _pin_inA;
        const uint8_t _pin_inB;
        const uint8_t _pin_PWM;
    
        int16_t _speed = 0;
        int16_t _min_speed = -254;
        int16_t _max_speed = 254;

    public:
        Motor(const uint8_t pin_inA, const uint8_t pin_inB, const uint8_t pin_PWM);
        Motor(const uint8_t pin_inA, const uint8_t pin_inB, const uint8_t pin_PWM, int16_t min_speed, int16_t max_speed);//Default:min:-254 max:254
        
        void setSpeed(int16_t speed);
        int16_t getSpeed();
};