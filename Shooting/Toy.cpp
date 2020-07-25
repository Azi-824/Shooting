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

//�N���b�N���ꂽ���̏���
void Toy::Event(Time* limit)
{
	DrawString(100, 300, "Toy��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	effect->DrawCenter(rect);		//�G�t�F�N�g�`��
	if (effect->GetIsEffectEnd())	//�G�t�F�N�g�`�悪�I�������
	{
		Score::AddScore(ScoreTable.at(Element));			//�X�R�A���Z
		effect->Reset();			//�G�t�F�N�g���Z�b�g
		img->SetIsDraw(false);		//�I��\��
		SetEventFlg(false);			//�C�x���g�I��
	}
	time->StartCount();		//�Čv��
}