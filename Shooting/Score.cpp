//Score.cpp
//�X�R�A���Ǘ�����N���X

//############ �w�b�_�t�@�C���ǂݍ��� ############
#include "Score.hpp"

//############ �N���X��` ################

int Score::score = 0;	//�X�R�A

//�R���X�g���N�^
Score::Score(){}

//�f�X�g���N�^
Score::~Score(){}

//�X�R�A�擾
int Score::GetScore()
{
	return score;
}

//�X�R�A���Z
void Score::AddScore(int value)
{
	score += value;	//���Z
}

//�X�R�A�`��
void Score::Draw()
{
	DrawFormatString(SCORE_DRAW_X, SCORE_DRAW_Y, COLOR_WHITE, "%d", score);
}
