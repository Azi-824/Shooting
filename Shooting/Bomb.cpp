//Bomb.cpp
//���e�i�}�C�i�X�̓I�j�̃N���X

//########## �w�b�_�t�@�C���ǂݍ��� ##############
#include "Bomb.hpp"

//########## �N���X��` ############

//�R���X�g���N�^ 
Bomb::Bomb(Image* img)
{
	this->img = img;	//�摜
	time->SetLimit(8);	//�������Ԑݒ�
}

//�f�X�g���N�^
Bomb::~Bomb(){}

//����s������
void Bomb::UpDate()
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
void Bomb::Event()
{
	DrawString(100, 300, "Bomb��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��
	Score::AddScore(score);	//�X�R�A���Z
}
