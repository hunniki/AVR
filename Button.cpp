
#include "Button.h"

char Button::buttonCheck(void){
	char btn_old;
	this->status = SW_UNKNOWN;
	btn_old = PIND;
	_delay_ms(10);
	if(((btn_old ^ PIND)& 0b01000000) == 0){
		status = (btn_old & 0b01000000) >> 6;
	}
	return status;
}