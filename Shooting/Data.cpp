//Data.cpp
//�f�[�^���Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Data.hpp"

//################# �N���X��` ###################

int Data::ElementCnt = 0;	//�v�f��

//�R���X�g���N�^
Data::Data(DATEDATA date, int score)
{
	//�����o�[������
	this->date = date;	//�f�[�^
	Score = score;		//�X�R�A
	Element = ElementCnt++;	//�v�f�ԍ�
}

//�R���X�g���N�^
Data::Data(int score)
{
	//�����o�[������
	date = { 0 };		//�f�[�^
	GetDateTime(&date);	//�f�[�^�擾
	Score = score;		//�X�R�A
}

//�f�X�g���N�^
Data::~Data() {}

//���t�f�[�^�ݒ�
void Data::SetDate(DATEDATA date)
{
	this->date = date;
}

//�X�R�A�ݒ�
void Data::SetScore(int score)
{
	Score = score;
}

//���t�f�[�^�擾
DATEDATA Data::GetDate()
{
	return date;
}

//�X�R�A�擾
int Data::GetScore()
{
	return Score;
}

//�X�R�A�`��
void Data::Draw()
{
	if (Element >= RANKING_DRAW_MAX)	//�`�悷��ő吔��葽�����
		return;	//�`�悹���I��

	string str;	//�`�敶����
	str = std::to_string(date.Year) + "�N";	//�N
	str += std::to_string(date.Mon) + "��";	//��
	str += std::to_string(date.Day) + "��";	//��
	str += std::to_string(Score) + "�_";	//�_

	int x = 0, y = 0;	//�`��ʒu
	int Strlen = 0;		//������̒���
	int width = 0;		//����

	if (Element == 0)	//�擪�̎���
	{
		Strlen = strlen(RANK_INDEX_TEXT);	//�����擾
		width = GetDrawStringWidthToHandle(RANK_INDEX_TEXT, Strlen, Font::GetNowHandle());	//�����擾
		x = (GAME_WIDTH / 2) - (width / 2);				//X�ݒ�
		DrawStringToHandle(x, RANKING_DRAW_Y, RANK_INDEX_TEXT, COLOR_WHITE, Font::GetNowHandle(), COLOR_BLACK);	//�\��`��
	}

	Strlen = strlen(str.c_str());	//�����擾
	width = GetDrawStringWidthToHandle(str.c_str(), Strlen, Font::GetNowHandle());	//�����擾
	int height = GetFontSizeToHandle(Font::GetNowHandle());	//�����擾
	x = (GAME_WIDTH / 2) - (width / 2);				//X�ݒ�
	y = (RANKING_DRAW_Y + height) * (Element + 1);	//Y�ݒ�

	DrawStringToHandle(x, y, str.c_str(), COLOR_WHITE, Font::GetNowHandle(), COLOR_BLACK);

}
