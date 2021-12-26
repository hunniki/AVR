/****************************************************************************************************/
/*		LCD�\�����C�u�����w�b�_�t�@�C��	�F	lcd.h													*/
/*																									*/
/*�@�{�w�b�_�t�@�C����OLED Display 0.96"���C�u�������g�p����v���O�����ɂăC���N���[�h���邱�ƁD			*/
/*�@�{���C�u�����ł́Ctwi.h�y��twi.c�𗘗p���Ă���C������������Build����K�v������D					*/
/*�@�{I2C�ʐM���C�u�����́COLED Display 0.96"��SDA�y��SCL�[�q�ɐڑ�����CLCD�f�o�C�X�A�h���X��0x78��		*/
/*�@�z�肵�Ă���DLCD�f�o�C�X�A�h���X���C������ꍇ�́CLCD_ADRS��define�l���C�����邱��					*/
/*																									*/
/*	�ύX����																							*/
/*�@���ʎq	���t			����					�ύX���e													*/
/*�@#000		2021.09.17	�r�� ����			���Ń����[�X												*/
/****************************************************************************************************/
#ifndef LCD_H_
#define LCD_H_
#include	"common.h"									/* ���ʃw�b�_�t�@�C��							*/
#include	"twi.h"										/* ���N���X�itwi�j�̃w�b�_�t�@�C��			*/
#include	<avr/pgmspace.h>							/* FONT��ROM�̈悩��ǂݏo�����߂̃w�b�_		*/

/* �f�o�C�X�A�h���X																					*/
#define LCD_ADRS	0x78								/* LCD�f�o�C�X��I2C�A�h���X					*/

/* LCD Class ��`																					*/
class	LCD:public twi{
	/* font �C���[�W�o�b�t�@�i[4�s][�s��+�s��][�s������16����][1����������8Byte]	�r�b�g�}�b�v�f�[�^		*/
	char lcdImage[4][2][16][8];							/* OLED �\���C���[�W�o�b�t�@					*/
	/* �L�����N�^�C���[�W�o�b�t�@ASCII�R�[�h(0x20-0x7F�j[4�s][1�s������16����]ASCII�R�[�h�̃f�[�^			*/
	char lcdChar[4][16];								/* OLED �L�����N�^�o�b�t�@					*/
  public:
	LCD( void);											/* �R���X�g���N�^								*/
	void	lcdPrint( int x, int y, char *str);			/* LCD�L�����N�^�o�b�t�@�ɕ�������������		*/
	void	lcdFlip();									/* LCD�L�����N�^�o�b�t�@�̃C���[�W�W�J�\��		*/
	void	lcdClr(void);								/* LCD�L�����N�^�y�уC���[�W�o�b�t�@�N���A		*/
	void	memFill( char *ptr, char data, int length);	/* ������Fill���\�b�h							*/
};

#endif /* LCD_H_ */