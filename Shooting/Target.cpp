//Target.cpp
//�I�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Target.hpp"

//################# �N���X��` ####################

//�R���X�g���N�^
Target::Target()
{
	//�����o�[������
	DrawX = 0;			//�`��X�ʒu
	DrawY = 0;			//�`��Y�ʒu
	score = 0;			//�X�R�A
	img = new Image();	//�摜
	time = new Time();	//����
	rect = { 0,0,0,0 };	//�̈�
}

//�f�X�g���N�^
Target::~Target()
{
	delete img;	//img�j��
	delete time;//time�j��
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
	time->StartCount();		//�v���J�n
}

//�`��ʒu����
void Target::CreateDrawPos()
{
	int max_x = GAME_WIDTH - img->GetWidth();	//�`��ʒuX�̍ő�l��ݒ�
	int max_y = GAME_HEIGHT - img->GetHeight();	//�`��ʒuY�̍ő�l��ݒ�
	DrawX = GetRand(max_x);	//�`��X�ʒu�ݒ�
	DrawY = GetRand(max_y);	//�`��Y�ʒu�ݒ�
}

//�`��
void Target::Draw()
{
	if (time->GetIsLimit())	//�������Ԃ��z������
	{
		img->SetIsDraw(false);	//�`�����߂�
	}
	img->Draw(DrawX, DrawY);	//�`��
}

//�̈�擾
RECT Target::GetRect()
{
	return rect;
}
