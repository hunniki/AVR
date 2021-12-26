#ifndef DISPAUTH_H_
#define DISPAUTH_H_

#include "lcd.h"
#include "common.h"
#define  AUTH_OK
#define  AUTH_NG

class DispAuth :public LCD{
	char password[4];
public:
	DispAuth(void);
	DispAuth(char *password);

	void DispLock(void);
	void DispPassword(char *pass);
	void DispUnlock(void);
	char passCheck(char *pass);
};

#endif /* DISPAUTH_H_ */