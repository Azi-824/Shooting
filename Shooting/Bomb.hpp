//Bomb.hpp
//���e�i�}�C�i�X�̓I�j�̃N���X

#pragma once

//########### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Target.hpp"

//########### �}�N����` #############
#define IMG_BOMB_DIR	R"(.\Image\Bomb)"	//���e�̉摜�̃f�B���N�g��

#define IMG_NAME_BOMB	R"(\bomb01.png)"	//���e01�̖��O

//########### �N���X��` #############
class Bomb : public Target	//Target���p��
{
public:

	Bomb(Image*,Effect*);	//�R���X�g���N�^
	~Bomb();				//�f�X�g���N�^

	void UpDate() override;	//����s������
	void Event() override;	//�N���b�N���ꂽ���̏���

};
