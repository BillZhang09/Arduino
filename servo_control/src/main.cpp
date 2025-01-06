#include <Arduino.h>
#include "Servo_zcc.h"

Servo_zcc servo_zcc(9);

void setup() {
  servo_zcc.servoAttach();
  Serial.begin(9600);
}

void loop() {
  servo_zcc.setPosition(0,50);
}