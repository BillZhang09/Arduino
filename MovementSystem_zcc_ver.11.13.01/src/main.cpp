#include <Arduino.h>
#include "movement.h"

const int16_t DeadZoneX_peak = 488;
const int16_t DeadZoneX_top = 512;
const int16_t DeadZoneY_peak = 488;
const int16_t DeadZoneY_top = 512;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  
}