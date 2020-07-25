//Bomb.cpp
//���e�i�}�C�i�X�̓I�j�̃N���X

//########## �w�b�_�t�@�C���ǂݍ��� ##############
#include "Bomb.hpp"

//########## �N���X��` ############

//�R���X�g���N�^ 
Bomb::Bomb(Image* img,Effect* effect)
{
	this->img = img;		//�摜
	this->effect = effect;	//�G�t�F�N�g
	time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//�������Ԑݒ�
}

//�f�X�g���N�^
Bomb::~Bomb(){}

//�N���b�N���ꂽ���̏���
void Bomb::Event(Time* limit)
{
	DrawString(100, 300, "Bomb��Event()", COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	effect->DrawCenter(rect);			//�G�t�F�N�g�`��
	if (effect->GetIsEffectEnd())		//�G�t�F�N�g�`�悪�I�������
	{
		Score::AddScore(ScoreTable.at(Element));			//�X�R�A���Z
		effect->Reset();				//�G�t�F�N�g���Z�b�g
		img->SetIsDraw(false);			//�I��\��
		limit->Add(BOMB_TIME_VALUE);	//���Ԃ����炷
		SetEventFlg(false);				//�C�x���g�I��
	}
	time->StartCount();		//�Čv��
}
