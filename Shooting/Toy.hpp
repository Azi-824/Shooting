//Toy.hpp
//�I�i�v���X�|�C���g�j�̃N���X

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� ################
#include "Target.hpp"

//############## �}�N����` #################
#define IMG_TOY_DIR		R"(.\Image\Toy)"	//��������̉摜�̃f�B���N�g��

#define IMG_NAME_TOY	R"(\toy01.png)"		//��������01�̖��O

//############## �N���X��` #################
class Toy : public Target	//Target�N���X���p��
{
public:

	Toy(Image*,Effect*);		//�R���X�g���N�^
	~Toy();						//�f�X�g���N�^

	void Event(Time*) override;	//�N���b�N���ꂽ���̏���

};
