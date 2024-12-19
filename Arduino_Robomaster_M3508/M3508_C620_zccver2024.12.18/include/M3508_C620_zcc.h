#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <FastPID.h>
#include <Kalman.h>
#include "mcp2515.h"


class M3508_C620
{
    private:    
        //const int16_t _motor_number;
        int16_t mechanical_angle = 0;
        int16_t _current_speed = 0;
        int16_t motor_raw_status[8];
        int16_t motor_status[4];
        int16_t output_current = 0;//used in PID
        
    public:
        M3508_C620();
        void init();
        void setPercentageSpeed(int16_t percentage_speed);//range(-100,100)
        void setCurrentSpeed(int16_t current_speed);
        int16_t motorPID(int16_t minRange,int16_t maxRange,int16_t motor_target_speed,int16_t motor_speed);
        void stopMotor();
        int16_t readMotor();

};