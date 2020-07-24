//Target.cpp
//�I�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Target.hpp"

//################# �N���X��` ####################

//�R���X�g���N�^
Target::Target()
{
	//�����o�[������
	DrawX = 0;				//�`��X�ʒu
	DrawY = 0;				//�`��Y�ʒu
	score = 0;				//�X�R�A
	EventFlg = false;		//�C�x���g�t���O
	img = new Image();		//�摜
	time = new Time();		//����
	effect = new Effect();	//�G�t�F�N�g
	rect = { 0,0,0,0 };		//�̈�
}

//�f�X�g���N�^
Target::~Target()
{
	delete img;		//img�j��
	delete time;	//time�j��
	delete effect;	//effect�j��
}

//�����ݒ�
void Target::SetInit(int score)
{
	img->SetInit();		//�摜�����ݒ�
	CreateDrawPos();	//�`��ʒu����
	//�̈�̐ݒ�
	rect.left = DrawX;						//��X
	rect.top = DrawY;						//��Y
	rect.right = DrawX + img->GetWidth();	//�EX
	rect.bottom = DrawY + img->GetHeight();	//�EY
	this->score = score;	//�X�R�A�ݒ�
	effect->SetInit();		//�G�t�F�N�g
	time->StartCount();		//�v���J�n
}

//���ʂ̃C�x���g����
void Target::CommonEvent()
{
	Score::AddScore(score);	//�X�R�A���Z
	effect->DrawCenter(rect);	//�G�t�F�N�g�`��
	if (effect->GetIsEffectEnd())	//�G�t�F�N�g�`�悪�I�������
	{
		effect->Reset();			//�G�t�F�N�g���Z�b�g
		img->SetIsDraw(false);		//�I��\��
		SetEventFlg(false);			//�C�x���g�I��
	}
	time->StartCount();		//�Čv��
}

//�`��ʒu����
void Target::CreateDrawPos()
{
	int max_x = GAME_WIDTH - img->GetWidth();	//�`��ʒuX�̍ő�l��ݒ�
	int max_y = GAME_HEIGHT - img->GetHeight();	//�`��ʒuY�̍ő�l��ݒ�
	DrawX = GetRand(max_x);	//�`��X�ʒu�ݒ�
	DrawY = GetRand(max_y);	//�`��Y�ʒu�ݒ�

	//�̈�̐ݒ�
	rect.left = DrawX;						//��X
	rect.top = DrawY;						//��Y
	rect.right = DrawX + img->GetWidth();	//�EX
	rect.bottom = DrawY + img->GetHeight();	//�EY
}

//�`��
void Target::Draw()
{
	img->Draw(DrawX, DrawY);	//�`��
}

//�N���b�N���ꂽ��
bool Target::OnClick()
{
	if (!img->GetIsDraw())	//�`�悵�Ă��Ȃ�����
		return false;		//�N���b�N�Ȃ�

	return Mouse::OnLeftClick(rect);
}

//�C�x���g�t���O�擾
bool Target::GetEventFlg()
{
	return EventFlg;
}

//�C�x���g�t���O�ݒ�
void Target::SetEventFlg(bool flg)
{
	EventFlg = flg;
}
