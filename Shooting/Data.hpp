//Data.hpp
//�f�[�^���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"

//################### �}�N����` #####################
#define RANKING_DRAW_X	200	//�����L���O�`��X�ʒu
#define RANKING_DRAW_Y	10	//�����L���O�`��Y�ʒu

#define RANK_INDEX_TEXT	"�����L���O"	//�\��e�L�X�g

#define RANKING_DRAW_MAX 10	//�`�悷��f�[�^�̍ő吔

//################### �N���X��` #####################
class Data
{

private:

	int Score;		//�X�R�A
	int Element;	//�v�f�ԍ�
	static int ElementCnt;	//�v�f��

	DATEDATA date;	//���t�f�[�^


public:

	Data(DATEDATA,int);	//�R���X�g���N�^
	Data(int);			//�R���X�g���N�^
	~Data();			//�f�X�g���N�^

	void SetDate(DATEDATA);	//���t�f�[�^�ݒ�
	void SetScore(int);		//�X�R�A�ݒ�

	DATEDATA GetDate();	//���t�f�[�^�擾
	int GetScore();		//�X�R�A�擾

	void Draw();		//�X�R�A�`��

};