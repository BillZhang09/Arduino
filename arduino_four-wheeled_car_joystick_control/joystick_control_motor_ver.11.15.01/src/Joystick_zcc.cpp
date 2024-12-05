#include "Joystick_zcc.h"

Joystick::Joystick(const uint8_t pin_Joystick_X,const uint8_t pin_Joystick_Y)
    :_pin_Joystick_X(pin_Joystick_X),_pin_Joystick_Y(pin_Joystick_Y){
}

int16_t Joystick::getRawX(){
    return analogRead(_pin_Joystick_X);
}

int16_t Joystick::getRawY(){
    return analogRead(_pin_Joystick_Y);
}

void Joystick::setDeadZoneX(const int16_t DeadZoneX_peak,const int16_t DeadZoneX_top){
    _DeadZoneX_peak = DeadZoneX_peak;
    _DeadZoneX_top = DeadZoneX_top;
}

void Joystick::setDeadZoneY(const int16_t DeadZoneY_peak,const int16_t DeadZoneY_top){
    _DeadZoneY_peak = DeadZoneY_peak;
    _DeadZoneY_top = DeadZoneY_top;
}

int16_t Joystick::getMapX(const int16_t _DeadZoneX_peak,const int16_t _DeadZoneX_top,
                          int16_t joystick_minValue, int16_t joystick_maxValue,
                          int16_t wheel_minValue, int16_t wheel_maxValue){
    if(getRawX() >= _DeadZoneX_peak && getRawX() <= _DeadZoneX_top){
        return 0;
    }else{
        return map(getRawX(),joystick_minValue,joystick_maxValue,wheel_minValue,wheel_maxValue);//0,1023,-254,254
    }
}

int16_t Joystick::getMapY(const int16_t _DeadZoneY_peak,const int16_t _DeadZoneY_top,
                          int16_t joystick_minValue, int16_t joystick_maxValue,
                          int16_t wheel_minValue, int16_t wheel_maxValue){
    if(getRawY() >= _DeadZoneY_peak && getRawY() <= _DeadZoneY_top){
        return 0;
    }else{
        return map(getRawY(),joystick_minValue,joystick_maxValue,wheel_minValue,wheel_maxValue);//0,1023,-254,254
    }
}

void Joystick::showRawValue(){
    Serial.print("RawX:");
    Serial.print(getRawX());
    Serial.print("RawY:");
    Serial.print(getRawY());
}

void Joystick::showMapValue(int16_t joystick_minValue, int16_t joystick_maxValue,
                            int16_t wheel_minValue, int16_t wheel_maxValue){
    Serial.print("MapX:");
    Serial.print(getMapX(_DeadZoneX_peak,_DeadZoneX_top,joystick_minValue,joystick_maxValue,wheel_minValue,wheel_maxValue));
    Serial.print("   MapY:");
    Serial.print(getMapY(_DeadZoneY_peak,_DeadZoneY_top,joystick_minValue,joystick_maxValue,wheel_minValue,wheel_maxValue));
}