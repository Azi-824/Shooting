//Target.cpp
//�I�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Target.hpp"

//################# �N���X��` ####################

vector<RECT> Target::use_rect;	//�g�p����Ă���̈�

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
	element_num = use_rect.size();	//���Ԗڂ̗v�f��
	use_rect.push_back(rect);		//�g�p�ςݗ̈�ǉ�
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

//����s������
void Target::UpDate()
{
	if (time->GetIsLimit())	//�������Ԃ𒴂�����
	{
		/*
		�`�悵�Ă���Ƃ��́A�`�������
		�`�悵�Ă��Ȃ����́A���̕`��܂ł̎��Ԃ��߂����Ƃ��̂��߁A�ĕ`�悷��
		*/
		img->SetIsDraw(!img->GetIsDraw());	//���݂̕`���Ԃ̋t��ݒ�
		do
		{
			CreateDrawPos();					//�`��ʒu�Đ���
		} while (RectOverRap());
		time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//�������Ԑݒ�
		time->StartCount();	//�v���J�n
	}
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
	use_rect.at(element_num) = rect;		//�g�p�ς݂̗̈���㏑��
}

//�����̗̈悪�A�g�p�ς݂��ǂ������ׂ�
//�߂�l: true �g�p�ς� : false ���g�p
bool Target::RectOverRap()
{
	int cnt = 0;	//�J�E���g�p
	for (auto r : use_rect)
	{
		if (element_num != cnt++)	//�����̗̈�ȊO��������
		{
			//�̈悪�d�Ȃ��Ă��邩����
			if (rect.left < r.right &&
				rect.right > r.left &&
				rect.top < r.bottom &&
				rect.bottom > r.top)
			{
				return true;	//�g�p�ς�
			}

		}

	}
	return false;	//���g�p
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
