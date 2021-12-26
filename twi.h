/********************************************************************************/
/*	twi class																	*/
/*																				*/
/*�@�{�t�@�C���� Grove Beginner Kit �ɂ�I2C�ʐM���s�����߂�twi class ���`����		*/
/*	���̂ł���D																	*/
/*																				*/
/*	�����񎖍�																	*/
/*�@		�EAtmega328 CPU��SCL�y��SDA�[�q��I2C�f�o�C�X���ڑ�����Ă�����̂Ƃ���D		*/ 
/*		�E���C�Z���X��GPL�ɏ�������̂Ƃ���D										*/
/*																				*/
/********************************************************************************/
/*	�ύX����																		*/
/*�@���ʎq	���t			����					�ύX���e								*/
/*�@#000		2021.07.26	�r�� ����			���Ń����[�X							*/
/********************************************************************************/
#ifndef TWI_H_
#define TWI_H_

#include 	"common.h"							/* ���ʃw�b�_�t�@�C��				*/

/* ��Ԓl��`																	*/
#define	START		0x08						/* �X�^�[�g��Ԓl					*/
#define	MT_SLA_ACK	0x18						/* SLA_W�𐳏푗�M�`�F�b�N�l		*/
#define	MT_DATA_ACK	0x28						/* �f�[�^�𐳏푗�M�`�F�b�N�l		*/

class twi{
	UCHR	slaveAddress;						/* �X���[�u�f�o�C�X�A�h���X		*/
public:
	twi( UCHR slave_address);					/* �R���X�g���N�^					*/
	void	twiStart( void);					/* TWI �ʐM�J�n					*/
	void	twiSend(UCHR twi_data);				/* TWI �f�[�^���M				*/
	void	twiStop(void);						/* TWI �f�[�^���M�I��				*/
	UCHR	twiRcv(UCHR *data, UCHR length);	/* TWI �f�[�^��M				*/
	void	twiError(int cd);					/* �G���[�������p���\�b�h			*/
};
#endif /* TWI_H_ */