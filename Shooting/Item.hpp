//Item.hpp
//�A�C�e���i���ԉ񕜌��ʂ����I�j�̃N���X

#pragma once

//########### �w�b�_�t�@�C���ǂݍ��� ############
#include "Target.hpp"

//########### �}�N����` ##############
#define IMG_ITEM_DIR	R"(.\Image\Item)"	//�A�C�e���̉摜�̃f�B���N�g��

#define IMG_NAME_ITEM	R"(\item.png)"		//�A�C�e���̖��O

#define ITEM_TIME_VALUE	5	//���₷����

//########### �N���X��` ##############
class Item : public Target	//Target���p��
{

public:

	Item(Image*, Effect*);		//�R���X�g���N�^
	~Item();					//�f�X�g���N�^

	void Event(Time*) override;	//�N���b�N���ꂽ���̏���

};
