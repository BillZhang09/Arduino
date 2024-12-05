#include "movement.h"

void Movement :: mecaunumMovement (int16_t mappedValue_x, int16_t mappedValue_y,
                            int16_t mappedValue_Left, int16_t mappedValue_Right){
    theta = atan2(mappedValue_y,mappedValue_x);
    power = hypot(mappedValue_x,mappedValue_y);
    turn = mappedValue_Left - mappedValue_Right;
    //turn = 0;
    sinAngle = sin(theta - PI/4);
    cosAngle = cos(theta - PI/4);
    maxi = max(abs(sinAngle),abs(cosAngle));
    //cosAngle = abs(cosAngle);
    /*
    Serial.print(sinAngle);
    Serial.print("       ");
    Serial.print(cosAngle);
    */
    FL_Speed = power * cosAngle / maxi + turn;
    FR_Speed = power * sinAngle / maxi - turn;
    BL_Speed = power * sinAngle / maxi + turn;
    BR_Speed = power * cosAngle / maxi - turn;
    
    /*if((power + abs(turn)) > 1){
        FL_Speed /= power + abs(turn);
        FR_Speed /= power + abs(turn);
        BL_Speed /= power + abs(turn);
        BR_Speed /= power + abs(turn);
    }*/
    //Serial.print(FL_Speed);
}

void Movement :: showDirection(int16_t MappedValue_Turn){
    Serial.print("Direction:");
    Serial.print(MappedValue_Turn);
}

void Movement :: mecaunumMovement (int16_t mappedValue_x, int16_t mappedValue_y, int16_t turn){
    theta = atan2(mappedValue_y,mappedValue_x);
    power = hypot(mappedValue_x,mappedValue_y);

    sinAngle = sin(theta - PI/4);
    cosAngle = cos(theta - PI/4);
    maxi = max(abs(sinAngle),abs(cosAngle));

    FL_Speed = power * cosAngle / maxi + turn;
    FR_Speed = power * sinAngle / maxi - turn;
    BL_Speed = power * sinAngle / maxi + turn;
    BR_Speed = power * cosAngle / maxi - turn;
}