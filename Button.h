/*
 * Button.h
 *
 * Created: 2021/12/20 11:16:44
 *  Author: huziw
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "common.h"

#define SW_OFF 0
#define SW_ON  1
#define SW_UNKNOWN 2

class Button{
	UCHR status;
public:
	Button(void);
	char buttonCheck(void);
};



#endif /* BUTTON_H_ */