//Bomb.hpp
//���e�i�}�C�i�X�̓I�j�̃N���X

#pragma once

//########### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Target.hpp"

//########### �}�N����` #############
#define IMG_BOMB_DIR	R"(.\Image\Bomb)"	//���e�̉摜�̃f�B���N�g��

#define IMG_NAME_BOMB01	R"(\bomb01.png)"	//���e01�̖��O
#define IMG_NAME_BOMB02	R"(\bomb02.png)"	//���e02�̖��O
#define IMG_NAME_BOMB03	R"(\bomb03.png)"	//���e03�̖��O

#define BOMB_TIME_VALUE		-10	//���炷����

//########### �N���X��` #############
class Bomb : public Target	//Target���p��
{
public:

	Bomb(Image*,Effect*);	//�R���X�g���N�^
	~Bomb();				//�f�X�g���N�^

	void Event(Time*) override;	//�N���b�N���ꂽ���̏���

};
