#include <Arduino.h>
#include "motor.h"
#include "Joystick_zcc.h"
#include "movement.h"

Joystick joystick(A10,A11);
Joystick joystick_back(A15,A14);
Motor motor_1(42,43,9);//FL
Motor motor_2(34,35,12);//FR
Motor motor_3(39,29,5);//BL 
Motor motor_4(37,36,8);//BR
Movement mecanum;

const int16_t DeadZoneX_peak = 468;
const int16_t DeadZoneX_top = 498;
const int16_t DeadZoneY_peak = 470;
const int16_t DeadZoneY_top = 510;

const int16_t DeadZoneBackLeft_peak = 0;
const int16_t DeadZoneBackLeft_top = 10;
const int16_t DeadZoneBackRight_peak = 0;
const int16_t DeadZoneBackRight_top = 10;

int16_t joystick_minValue = 0;
int16_t joystick_maxValue = 1023;

int16_t wheel_minValue = -254;
int16_t wheel_maxValue = 254;
int16_t mapped_back_minValue = 254;//init at 1023
int16_t mapped_back_maxValue = 0;//joystick at back

int16_t MapX,MapY,MapLeft,MapRight,MapTurn;

void setup(){
    Serial.begin(9600);
}

void loop(){
    joystick.setDeadZoneX(DeadZoneX_peak,DeadZoneX_top);
    joystick.setDeadZoneY(DeadZoneY_peak,DeadZoneY_top);
    MapX = joystick.getMapX(DeadZoneX_peak,DeadZoneX_top,
                            joystick_minValue,joystick_maxValue,
                            wheel_minValue,wheel_maxValue);
    MapY = joystick.getMapY(DeadZoneY_peak,DeadZoneY_top,
                            joystick_minValue,joystick_maxValue,
                            wheel_minValue,wheel_maxValue);
    MapLeft = joystick_back.getMapX(DeadZoneBackLeft_peak,DeadZoneBackLeft_top,
                                    joystick_minValue,joystick_maxValue,
                                    mapped_back_minValue,mapped_back_maxValue);
    MapRight = joystick_back.getMapY(DeadZoneBackLeft_peak,DeadZoneBackLeft_top,
                                    joystick_minValue,joystick_maxValue,
                                    mapped_back_minValue,mapped_back_maxValue);
    MapTurn = joystick_back.getMapX(0,20,1023,0,-254,254);
    //mecanum.mecaunumMovement(MapX,MapY,MapLeft,MapRight);
    mecanum.mecaunumMovement(MapX,MapY,MapTurn);
    motor_1.setSpeed(mecanum.speed_FL());
    motor_2.setSpeed(mecanum.speed_FR());
    motor_3.setSpeed(mecanum.speed_BL());
    motor_4.setSpeed(mecanum.speed_BR());
    //MapTurn = MapLeft - MapRight;
    //mecanum.showDirection(MapTurn);
    //joystick.showMapValue(joystick_minValue,joystick_maxValue,wheel_minValue,wheel_maxValue);
    //joystick.showRawValue();
    Serial.println();
    /*motor_1.setSpeed(254);
    motor_2.setSpeed(254);
    motor_3.setSpeed(254);
    motor_4.setSpeed(254);

    *//*mecanum.mecaunumMovement(MapX,MapY,MapLeft,MapRight);

    motor_1.setSpeed(mecanum.speed_FL());
    motor_2.setSpeed(mecanum.speed_FR());
    motor_3.setSpeed(mecanum.speed_BL());
    motor_4.setSpeed(mecanum.speed_BR());

    MapTurn = MapLeft - MapRight;
    *//*
    Serial.print("LF:");
    motor_1.getSpeed();
    Serial.print("  LR:");
    motor_2.getSpeed();
    Serial.print("  BL:");
    motor_3.getSpeed();
    Serial.print("  BR:");
    motor_4.getSpeed();
    //motor_1.setSpeed(MapY);
    joystick.showRawValue();
    joystick.showMapValue(joystick_minValue,joystick_maxValue,wheel_minValue,wheel_maxValue);
    mecanum.showDirection(MapTurn);
    Serial.println();
    */
}
