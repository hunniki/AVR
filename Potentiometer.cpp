#include "Potentiometer.h"

Potentiometer::Potentiometer(void){
	DDRC &= 0b11111110;
	ADCSRA = 0b10000100;
	ADMUX = 0b01100000;
	this->potAd = 0; 
}

UCHR Potentiometer::getPotAd(void){
	ADCSRA |= 0b01000000;
	while((ADCSRA & 0b01000000) != 0);
	this->potAd = ADCH;
	return this->potAd; 
}

