#include <Arduino.h>
#include "mcp2515.h"
#include"M3508_C620_zcc.h"


//53: Mega 2560 Rev3 CS

M3508_C620 M1;

void setup() {
  Serial.begin(115200);
  M1.init();
  
    
  /*canMsg1.data[0] = highByte(-1000);
  canMsg1.data[1] = lowByte(1000);*/
 
}

void loop() {
  M1.setCurrentSpeed(M1.motorPID(-3000,3000,2000,M1.readMotor()));
  //Serial.println(M1.motorPID(500,M1.readMotor()));
  Serial.println(M1.readMotor());
}
