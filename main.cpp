/**********************************************************/
/* TK210553 ���c �W�� */
/**********************************************************/
#include "common.h"   /*���ʃw�b�_*/
#include "DispAuth.h"  /*LCD�N���X��`�t�@�C��*/
#include "Number.h"   /*�l�擾�N���X��`�t�@�C��*/
#include "Button.h"   /*Button �N���X��`�t�@�C��*/


int main(void)
{
    char pass[4] = {1,2,3,4};
	char passcode[4];       /*���̓p�X���[�h��ۑ����郁����*/
	int lock = AUTH_NG;     
	Button b1;				/*Button�C���X�^���X����*/
	DispAuth d1(pass);		
	Number n1;
	UCHR digit[2];
	digit[0] = n1.getNumber(); 
    while (1){
		if(lock == AUTH_NG){   /*�p�X���[�h�s��v�̎�*/
			d1.DispLock();     /*Locd��ʕ\��*/
		}else{				   /*�p�X���[�h��v�̎�*/
			d1.DispUnlock();   /*Unlock��ʕ\��*/
		}
		while(b1.buttonCheck() != SW_ON);  /*Button �����������܂ő҂�*/
		while(b1.buttonCheck() != SW_OFF); /*Button �����������܂ő҂�*/
		for (int i=0;i<4;i++){				/*4�����̓��̓p�X���[�h��������*/
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

