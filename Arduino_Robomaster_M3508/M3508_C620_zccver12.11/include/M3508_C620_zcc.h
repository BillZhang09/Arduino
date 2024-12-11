#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>

class M3508_C620
{
    private:
        const int16_t _motor_number;


    public:
        M3508_C620(const uint8_t motor_number);
        void setSpeed(int16_t percentage_speed);

};