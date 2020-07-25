//Item.cpp
//�A�C�e���i���ԉ񕜌��ʂ����I�j�̃N���X

//######## �w�b�_�t�@�C���ǂݍ��� ############
#include "Item.hpp"

//########### �N���X��` ##############

//�R���X�g���N�^
//����:Image* : �I�̉摜
//����:Effect* :�G�t�F�N�g
Item::Item(Image* img, Effect* effect)
{
	this->img = img;		//�摜
	this->effect = effect;	//�G�t�F�N�g
	time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//�������Ԑݒ�
}

//�f�X�g���N�^
Item::~Item() {}

//�N���b�N���ꂽ���̏���
void Item::Event(Time* limit)
{
	effect->DrawCenter(rect);			//�G�t�F�N�g�`��
	if (effect->GetIsEffectEnd())		//�G�t�F�N�g�`�悪�I�������
	{
		effect->Reset();				//�G�t�F�N�g���Z�b�g
		img->SetIsDraw(false);			//�I��\��
		limit->Add(ITEM_TIME_VALUE);	//���Ԃ����Z
		SetEventFlg(false);				//�C�x���g�I��
	}

	time->StartCount();		//�Čv��
}
