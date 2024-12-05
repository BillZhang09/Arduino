#pragma once
#include <Arduino.h>

class Movement
{   
    private:
        double theta, power,turn;
        double sinAngle, cosAngle, max;

        double FL_Speed, FR_Speed, BL_Speed, BR_Speed;
        uint8_t dir[4];
        int deadzone = 20;
        
        bool flag;
    public:
        void mecaunumMovement (int16_t mappedValue_x, int16_t mappedValue_y, int16_t mappedValue_Left, int16_t mappedValue_Right);
        void showDirection(int16_t MappedValue_Turn);
        
        double speed_FL() { return FL_Speed; };
        double speed_FR() { return FR_Speed; };
        double speed_BL() { return BL_Speed; };
        double speed_BR() { return BR_Speed; };
};   