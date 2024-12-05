#include "movement.h"

void Movement :: mecaunumMovement (int16_t mappedValue_x, int16_t mappedValue_y,
                            int16_t mappedValue_Left, int16_t mappedValue_Right){
    theta = atan2(mappedValue_y,mappedValue_x);
    power = hypot(mappedValue_x,mappedValue_y);
    turn = mappedValue_Left - mappedValue_Right;

    sinAngle = sin(theta - PI/4);
    cosAngle = cos(theta - PI/4);
    max = max(abs(sinAngle),abs(cosAngle));
    abs(cosAngle);

    FL_Speed = power * cosAngle / max + turn;
    FR_Speed = power * sinAngle / max - turn;
    BL_Speed = power * sinAngle / max + turn;
    BR_Speed = power * cosAngle / max - turn;

    if((power + abs(turn)) > 1){
        FL_Speed /= power + turn;
        FR_Speed /= power + turn;
        BL_Speed /= power + turn;
        BR_Speed /= power + turn;
    }
}

void Movement :: showDirection(int16_t MappedValue_Turn){
    Serial.print("Direction:");
    Serial.print(MappedValue_Turn);
}

double Movement :: speed_FL() { return FL_Speed; };
double Movement :: speed_FR() { return FR_Speed; };
double Movement :: speed_BL() { return BL_Speed; };
double Movement :: speed_BR() { return BR_Speed; };