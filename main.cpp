/**********************************************************/
/* TK210553 高田 晃希 */
/**********************************************************/
#include "common.h"   /*共通ヘッダ*/
#include "DispAuth.h"  /*LCDクラス定義ファイル*/
#include "Number.h"   /*値取得クラス定義ファイル*/
#include "Button.h"   /*Button クラス定義ファイル*/


int main(void)
{
    char pass[4] = {1,2,3,4};
	char passcode[4];       /*入力パスワードを保存するメモリ*/
	int lock = AUTH_NG;     
	Button b1;				/*Buttonインスタンス生成*/
	DispAuth d1(pass);		
	Number n1;
	UCHR digit[2];
	digit[0] = n1.getNumber(); 
    while (1){
		if(lock == AUTH_NG){   /*パスワード不一致の時*/
			d1.DispLock();     /*Locd画面表示*/
		}else{				   /*パスワード一致の時*/
			d1.DispUnlock();   /*Unlock画面表示*/
		}
		while(b1.buttonCheck() != SW_ON);  /*Button が押下されるまで待つ*/
		while(b1.buttonCheck() != SW_OFF); /*Button が押下されるまで待つ*/
		for (int i=0;i<4;i++){				/*4桁分の入力パスワードを初期化*/
			passcode[i] = 0xFF;
		}
		for (int i=0;i<4;i++){
			digit[1] = -1;
			while(b1.buttonCheck()==SW_OFF){
				digit[0] = n1.getNumber();
				if(digit[0] != digit[1]){
					digit[1] = digit[0];
					passcode[i] = digit[0];
					d1.DispPassword(passcode);
				}
			}
			while(b1.buttonCheck() != SW_OFF);
		}
		lock = d1.passCheck(passcode);
    }
	return 0;
}

