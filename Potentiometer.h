#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

class Potentiometer{
	UCHR potAd;
	UCHR threshold;
	public:
	Potentiometer(void);
	UCHR getPotAd(void);
};



#endif /* POTENTIOMETER_H_ */