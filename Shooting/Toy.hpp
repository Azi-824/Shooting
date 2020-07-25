//Toy.hpp
//�I�i�v���X�|�C���g�j�̃N���X

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� ################
#include "Target.hpp"

//############## �}�N����` #################
#define IMG_TOY_DIR		R"(.\Image\Toy)"	//��������̉摜�̃f�B���N�g��

#define IMG_NAME_TOY01	R"(\toy01.png)"		//��������01�̖��O
#define IMG_NAME_TOY02	R"(\toy02.png)"		//��������02�̖��O
#define IMG_NAME_TOY03	R"(\toy03.png)"		//��������03�̖��O

//############## �N���X��` #################
class Toy : public Target	//Target�N���X���p��
{
public:

	Toy(Image*,Effect*);		//�R���X�g���N�^
	~Toy();						//�f�X�g���N�^

	void Event(Time*) override;	//�N���b�N���ꂽ���̏���

};
