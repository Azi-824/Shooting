//Bomb.cpp
//���e�i�}�C�i�X�̓I�j�̃N���X

//########## �w�b�_�t�@�C���ǂݍ��� ##############
#include "Bomb.hpp"

//########## �N���X��` ############

//�R���X�g���N�^ 
Bomb::Bomb(Image* img)
{
	this->img = img;	//�摜
}

//�f�X�g���N�^
Bomb::~Bomb(){}

//�N���b�N���ꂽ���̏���
void Bomb::Event()
{
	DrawString(100, 300, "Bomb��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��
	Score::AddScore(score);	//�X�R�A���Z
}
