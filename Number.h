#ifndef NUMBER_H_
#define NUMBER_H_

#include "Potentiometer.h"
#include "common.h"

class Number :public Potentiometer{
	char number;
	char maxNumber;
	char minNumber;
	public:
	Number(void);
	Number(char max,char min);
	char getNumber(void);
	
};



#endif /* NUMBER_H_ */