#ifndef MHFF_h
#define MHFF_h

#include <Arduino.h>

class MHFF
{
	pubilc:
 	int val_pin1 = 0;
 	int val_pin2 = 0;
 	
 	void init1(uint8_t pin1,uint8_t lightpin);
 	void init2(uint8_t pin1,uint8_t pin2,uint8_t lightpin);
 	int getInfoWithLight1(void);
 	int getInfoWithLight2(void);
 	
 	private:
	uint8_t MHFF_pin1;
	uint8_t MHFF_pin2;
	uint8_t MHFF_lightpin;
};

#endif
