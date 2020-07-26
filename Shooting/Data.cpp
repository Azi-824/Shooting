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

	if (Element == 0)	//�擪�̎���
		DrawStringToHandle(RANKING_DRAW_X, RANKING_DRAW_Y, RANK_INDEX_TEXT, COLOR_WHITE, Font::GetNowHandle(), COLOR_BLACK);	//�\��`��
	int height = GetFontSizeToHandle(Font::GetNowHandle());	//�����擾
	DrawStringToHandle(RANKING_DRAW_X, (RANKING_DRAW_Y + height) * (Element + 1), str.c_str(), COLOR_WHITE, Font::GetNowHandle(), COLOR_BLACK);

}
