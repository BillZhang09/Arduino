#include "M3508_C620_zcc.h"

MCP2515 mcp2515(53);
struct can_frame canWrite;
struct can_frame canRead;
double Kp = 10.0, Ki = 2.0, Kd = 0.3;
double process_noise = 0.1, sensor_noise = 10, estimated_error = 100, intial_value = 0;
FastPID speedPID(Kp, Ki, Kd, 10, 8, true);
Kalman myFilter(process_noise,sensor_noise,estimated_error,intial_value);

//double Kp = 1.5, Ki = 0.5, Kd = 0.1;
//double process_noise = 0.1, sensor_noise = 10, estimated_error = 8000, intial_value = 0;

M3508_C620 :: M3508_C620(){
    //struct can_frame canMsg2;
    
    // if(_motor_number <= 4){
    //     canWrite.can_dlc = 2*_motor_number;
    // }else{
    //     canWrite.can_dlc = 8;
    //     //canMsg2.can_dlc = (_motor_number - 4)*2;
    // }
    
    //canMsg2.can_id = 0x1FF;
}

void M3508_C620 :: init(){
    canWrite.can_id = 0x200;
    canWrite.can_dlc = 2;
    canRead.can_id = 0x201;
    canRead.can_dlc = 8;

    mcp2515.reset();
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();
}

void M3508_C620 :: setPercentageSpeed(int16_t percentage_speed){
    _current_speed = map(percentage_speed,-100,100,-16384,16384);
    canWrite.data[0] = highByte(_current_speed);
    canWrite.data[1] = lowByte(_current_speed);
    mcp2515.sendMessage(&canWrite);
}

void M3508_C620 :: setCurrentSpeed(int16_t current_speed){
    _current_speed = current_speed;
    canWrite.data[0] = highByte(_current_speed);
    canWrite.data[1] = lowByte(_current_speed);
    mcp2515.sendMessage(&canWrite);
}

int16_t M3508_C620 :: motorPID(int16_t minRange,int16_t maxRange,int16_t motor_target_speed,int16_t motor_speed){
    speedPID.setOutputRange(minRange,maxRange);
    output_current = speedPID.step(motor_target_speed, (int)myFilter.getFilteredValue(motor_speed));
    return output_current;
}

void M3508_C620 :: stopMotor(){
    canWrite.data[0] = 0x00;
    canWrite.data[1] = 0x00;
}

int16_t M3508_C620 :: readMotor(){
    mcp2515.readMessage(&canRead);
    for(int i = 0;i < 8;i++){
        motor_raw_status[i] = canRead.data[i];
    }
    for(int i = 0;i < 3;i += 1){
        motor_status[i] = word(motor_raw_status[i*2],motor_raw_status[i*2+1]);
    }
    motor_status[3] = motor_raw_status[6];
    mechanical_angle = map(motor_status[0],0,8192,0,360);
    return motor_status[1];
    /*
    Serial.print("Rotor mechanical angle(0-8192):"); Serial.print(motor_status[0]);
    Serial.print("\n");
    Serial.print("Rotor mechanical angle(0-360degree):"); Serial.print(mechanical_angle);
    Serial.print("\n");
    Serial.print("Rotational speed:"); Serial.print(motor_status[1]); Serial.print("RPM");
    Serial.print("\n");
    Serial.print("Actual torque current:"); Serial.print(motor_status[2]);
    Serial.print("\n");
    Serial.print("Motor temperature:"); Serial.print(motor_status[3]);
    Serial.print("\n");
    */

    //return canRead.data;//unknown to use
}