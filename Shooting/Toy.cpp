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

//�N���b�N���ꂽ���̏���
void Toy::Event()
{
	DrawString(100, 300, "Toy��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��
	Score::AddScore(score);	//�X�R�A���Z
	
}