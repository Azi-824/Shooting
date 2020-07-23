//Score.hpp
//�X�R�A���Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� #############
#include "Global.hpp"

//############ �}�N����` #################
#define SCORE_DRAW_X	300	//�X�R�A�`��X�ʒu
#define SCORE_DRAW_Y	300	//�X�R�A�`��Y�ʒu

//############ �N���X��` #############
class Score
{
private:

	static int score;		//�X�R�A

public:

	Score();		//�R���X�g���N�^
	~Score();		//�f�X�g���N�^

	static int GetScore();			//�X�R�A�擾
	static void AddScore(int);		//�X�R�A���Z
	static void Draw();				//�X�R�A�`��

};
