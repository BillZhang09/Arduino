#include <Arduino.h>
#include "mcp2515.h"
#include"M3508_C620_zcc.h"


//53: Mega 2560 Rev3 CS

M3508_C620 M1;

void setup() {
  Serial.begin(115200);
  M1.init();
 
}

void loop() {
  M1.setCurrentSpeed(M1.motorPID(-3000,3000,2000,M1.readMotor()));
  Serial.println(M1.readMotor());
}
