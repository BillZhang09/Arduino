#pragma once
#include <Arduino.h>

class Joystick{
    private:
        const uint16_t _pin_Joystick_X;
        const uint16_t _pin_Joystick_Y;
        int16_t _DeadZoneX_peak,_DeadZoneX_top,_DeadZoneY_peak,_DeadZoneY_top;


    public:
        Joystick(const uint8_t pin_Joystick_X,const uint8_t pin_Joystick_Y);

        int16_t getRawX();
        int16_t getRawY();

        void setDeadZoneX(const int16_t DeadZoneX_peak,const int16_t DeadZoneX_top);
        void setDeadZoneY(const int16_t DeadZoneY_peak,const int16_t DeadZoneY_top);

        int16_t getMapX(const int16_t _DeadZoneX_peak,const int16_t _DeadZoneX_top,
                        int16_t joystick_minValue, int16_t joystick_maxValue,
                        int16_t wheel_minValue, int16_t wheel_maxValue);
        int16_t getMapY(const int16_t _DeadZoneY_peak,const int16_t _DeadZoneY_top,
                        int16_t joystick_minValue, int16_t joystick_maxValue,
                        int16_t wheel_minValue, int16_t wheel_maxValue);

        void showRawValue();
        void showMapValue(int16_t joystick_minValue, int16_t joystick_maxValue,
                          int16_t wheel_minValue, int16_t wheel_maxValue);

        
};