//Data.cpp
//�f�[�^���Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Data.hpp"

//################# �N���X��` ###################

//�R���X�g���N�^
Data::Data(DATEDATA date, int score)
{
	//�����o�[������
	this->date = date;	//�f�[�^
	Score = score;		//�X�R�A
}

//�R���X�g���N�^
Data::Data(int score)
{
	//�����o�[������
	date = { 0 };		//�f�[�^
	GetDateTime(&date);	//�f�[�^�擾
	Score = score;		//�X�R�A
}

//�f�X�g���N�^
Data::~Data() {}

//���t�f�[�^�ݒ�
void Data::SetDate(DATEDATA date)
{
	this->date = date;
}

//�X�R�A�ݒ�
void Data::SetScore(int score)
{
	Score = score;
}

//���t�f�[�^�擾
DATEDATA Data::GetDate()
{
	return date;
}

//�X�R�A�擾
int Data::GetScore()
{
	return Score;
}
