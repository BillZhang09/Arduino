#include "M3508_C620_zcc.h"

MCP2515 mcp2515(53);
struct can_frame canMsg1;

M3508_C620 :: M3508_C620(){
    //struct can_frame canMsg2;
    
    // if(_motor_number <= 4){
    //     canMsg1.can_dlc = 2*_motor_number;
    // }else{
    //     canMsg1.can_dlc = 8;
    //     //canMsg2.can_dlc = (_motor_number - 4)*2;
    // }
    
    //canMsg2.can_id = 0x1FF;
}

void M3508_C620 :: init(){
    canMsg1.can_id = 0x200;
    canMsg1.can_dlc = 2;

    mcp2515.reset();
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();
}

void M3508_C620 :: setPercentageSpeed(int16_t percentage_speed){
    _current_speed = map(percentage_speed,-100,100,-16384,16384);
    canMsg1.data[0] = highByte(_current_speed);
    canMsg1.data[1] = lowByte(_current_speed);
    mcp2515.sendMessage(&canMsg1);
}

void M3508_C620 :: setCurrentSpeed(int16_t current_speed){
    _current_speed = current_speed;
    canMsg1.data[0] = highByte(_current_speed);
    canMsg1.data[1] = lowByte(_current_speed);
    mcp2515.sendMessage(&canMsg1);
}

void M3508_C620 :: stopMotor(){
    canMsg1.data[0] = 0x00;
    canMsg1.data[1] = 0x00;
}

