#include "MHFF.h"

void MHFF::init1(uint8_t pin1,uint8_t lightpin)//only choose 1 program in init1 and init2 to run
{
    MHFF_pin1 = pin1;
	MHFF_lightpin = lightpin;
	pinMode(MHFF_pin1,INPUT);
	pinMode(MHFF_lightpin,OUTPUT);
	Serial.begin(9600);
}
void MHFF::init2(uint8_t pin1,uint_t pin2,uint_t lightpin)
{
	MHFF_pin1 = pin1;
	MHFF_pin2 = pin2;
	MHFF_lightpin = lightpin;
	pinMode(MHFF_pin1,INPUT);
	pinMode(MHFF_pin2,INPUT);
	pinMode(MHFF_lightpin,OUTPUT);
	Serial.begin(9600);
}
int MHFF::getInfoWithLight1()
{
	val_pin1 = digitalRead(MHFF_pin1);
	Serial.println(val_pin1); // debug value
	if(val_pin1 == 1){
		digitalWrite(MHFF_lightpin,HIGH);
	}else{
		digitalWrite(MHFF_lightpin,LOW);
	}
	return ;
}
