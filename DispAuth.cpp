#include "DispAuth.h"

DispAuth::DispAuth(void){
	for(int i=0;i<4;i++){
		this->password[i] = i+1;
	}
}
DispAuth::DispAuth(char *password){
	for(int i=0;i<4;i)
	{ 
		this->password[i] = password[i];
	}
}
void DispAuth::DispLock(){/*ロック画面*/
	lcdClr();
	char lockdisp[4][17] = {"****************","****Locked!*****","**Push Button!**","****************"};
	for(int i = 0;i<4;i++){
		lcdPrint(0,i,&lockdisp[i][0]);
	}
	lcdFlip();
}
void DispAuth::DispPassword(char *pass){
	char notin[5] = "----";
	char psspri[10] = "Password:";
	
	
		
}
void DispAuth::DispUnlock(){ /*アンロック画面*/
	lcdClr();
	char unlockdisp[4][17] = {"+--------------+","|   Unlocked!  |","| Push Button! |","+--------------+"};
	for(int i = 0;i<4;i++){
		lcdPrint(0,i,&unlockdisp[i][0]);
	}
	lcdFlip();
}
