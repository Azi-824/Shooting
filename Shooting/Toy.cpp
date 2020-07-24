//Toy.cpp
//�I�i�v���X�|�C���g�j�̃N���X

//############## �w�b�_�t�@�C���ǂݍ��� ################
#include "Toy.hpp"

//############## �N���X��` ###################

//�R���X�g���N�^
//����:Image* : �I�̉摜
//����:Effect* :�G�t�F�N�g
Toy::Toy(Image* img,Effect* effect)
{
	this->img = img;		//�摜
	this->effect = effect;	//�G�t�F�N�g
	time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//�������Ԑݒ�
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
		CreateDrawPos();					//�`��ʒu�Đ���
		time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//�������Ԑݒ�
		time->StartCount();	//�v���J�n
	}

	if (GetEventFlg())	//�C�x���g�t���O�������Ă���Ƃ�
	{
		Event();	//�C�x���g����
	}
}

//�N���b�N���ꂽ���̏���
void Toy::Event()
{
	DrawString(100, 300, "Toy��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��
	CommonEvent();	//���ʂ̃C�x���g����
}