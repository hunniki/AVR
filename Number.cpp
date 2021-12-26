#include "Number.h"

Number::Number(void){
	this->number = 0;
	this->maxNumber = 9;
	this->minNumber = 0;
}

Number::Number(char max,char min){
	this->number = 0;
	this->maxNumber = max;
	this->minNumber = min;
}

char Number::getNumber(void){
	char mx;
	char mn;
	mx = this->maxNumber;
	mn = this->minNumber;
	this->number = getPotAd()/(255/(mx-mn))+minNumber;
	return this->number;
}