#include "M3508_C620_zcc.h"


M3508_C620 :: M3508_C620(const int16_t motor_number) : _motor_number(motor_number){
    struct can_frame canMsg1;
    struct can_frame canMsg2;
    
    if(_motor_number <= 4){
        canMsg1.can_dlc = 2*_motor_number;
    }else{
        canMsg1.can_dlc = 8;
        canMsg2.can_dlc = (_motor_number - 4)*2;
    }

    canMsg1.can_id = 0x200;
    canMsg2.can_id = 0x1FF;

    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();
}

void setSpeed(int16_t percentage_speed){
    
}

