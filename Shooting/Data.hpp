//Data.hpp
//�f�[�^���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"

//################### �}�N����` #####################
#define DATA_MAX	10	//�f�[�^�̍ő吔

//################### �N���X��` #####################
class Data
{

private:

	int Score;		//�X�R�A

	DATEDATA date;	//���t�f�[�^


public:

	Data(DATEDATA,int);	//�R���X�g���N�^
	Data(int);			//�R���X�g���N�^
	~Data();			//�f�X�g���N�^

	void SetDate(DATEDATA);	//���t�f�[�^�ݒ�
	void SetScore(int);		//�X�R�A�ݒ�

	DATEDATA GetDate();	//���t�f�[�^�擾
	int GetScore();		//�X�R�A�擾

};
