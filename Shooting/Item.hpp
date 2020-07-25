//Item.hpp
//�A�C�e���i���ԉ񕜌��ʂ����I�j�̃N���X

#pragma once

//########### �w�b�_�t�@�C���ǂݍ��� ############
#include "Target.hpp"

//########### �}�N����` ##############
#define IMG_ITEM_DIR	R"(.\Image\Item)"	//�A�C�e���̉摜�̃f�B���N�g��

#define IMG_NAME_ITEM01	R"(\item.png)"		//�A�C�e��01�̖��O
#define IMG_NAME_ITEM02	R"(\item02.png)"	//�A�C�e��02�̖��O

#define ITEM_TIME_VALUE	5	//���₷����

//########### �N���X��` ##############
class Item : public Target	//Target���p��
{

public:

	Item(Image*, Effect*);		//�R���X�g���N�^
	~Item();					//�f�X�g���N�^

	void Event(Time*) override;	//�N���b�N���ꂽ���̏���

};
