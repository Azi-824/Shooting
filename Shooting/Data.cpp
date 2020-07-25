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

	if (Element == 0)	//�擪�̎���
		DrawStringToHandle(RANKING_DRAW_X, RANKING_DRAW_Y, RANK_INDEX_TEXT, COLOR_GREEN, Font::GetNowHandle());	//�\��`��
	int height = GetFontSizeToHandle(Font::GetNowHandle());	//�����擾
	DrawFormatStringToHandle(RANKING_DRAW_X, (RANKING_DRAW_Y + height) * (Element + 1), COLOR_GREEN, Font::GetNowHandle(),"%d�N %d�� %d�� %d�_", date.Year, date.Mon, date.Day, Score, COLOR_WHITE);
}
