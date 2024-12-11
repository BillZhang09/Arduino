#include "M3508_C620_zcc.h"

MCP2515 mcp2515(53);//53: Mega 2560 Rev3 CS

void setup() {
  while (!Serial);
  Serial.begin(115200);
  
  canMsg1.data[0] = 0x10;
  canMsg1.data[1] = 0x00;

  Serial.println("Example: Write to CAN");
}

void loop() {
  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg1);
}