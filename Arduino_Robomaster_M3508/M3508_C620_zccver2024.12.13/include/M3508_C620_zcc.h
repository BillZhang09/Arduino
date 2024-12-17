#pragma once
#include <Arduino.h>
#include <SPI.h>
#include "mcp2515.h"


class M3508_C620
{
    private:
        //const int16_t _motor_number;
        int16_t _current_speed = 0;
    
    public:
        M3508_C620();
        void init();
        void setPercentageSpeed(int16_t percentage_speed);//range(-100,100)
        void setCurrentSpeed(int16_t current_speed);
        void stopMotor();
};
