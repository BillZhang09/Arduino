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
 Serial.println("Example: Write to CAN");
}

void loop() {
  M1.setPercentageSpeed(-10);
  
}
