//Toy.cpp
//�I�i�v���X�|�C���g�j�̃N���X

//############## �w�b�_�t�@�C���ǂݍ��� ################
#include "Toy.hpp"

//############## �N���X��` ###################

//�R���X�g���N�^
//����:Image* : �I�̉摜
Toy::Toy(Image* img)
{
	this->img = img;	//�摜
	time->SetLimit(5);	//�������Ԑݒ�
}

//�f�X�g���N�^
Toy::~Toy(){}

//����s������
void Toy::UpDate()
{
	if (time->GetIsLimit())	//�������Ԃ𒴂�����
	{
		/*
		�`�悵�Ă���Ƃ��́A�`�������
		�`�悵�Ă��Ȃ����́A���̕`��܂ł̎��Ԃ��߂����Ƃ��̂��߁A�ĕ`�悷��
		*/
		img->SetIsDraw(!img->GetIsDraw());	//���݂̕`���Ԃ̋t��ݒ�
		time->StartCount();	//�v���J�n
	}
}

//�N���b�N���ꂽ���̏���
void Toy::Event()
{
	DrawString(100, 300, "Toy��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��
	Score::AddScore(score);	//�X�R�A���Z
	time->StartCount();		//�Čv��
	
}