//Time.hpp
//���Ԃ��Ǘ�����N���X

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� #############
#include "Global.hpp"

//############## �}�N����` ##############

//############## �N���X��` ##############
class Time
{

private:

	int StartTime;						//�v���J�n����
	int ElapsedTime;					//�o�ߎ���
	int LimitTime;						//��������
	int LimitInit;						//�������Ԃ̏����l

public:

	Time();								//�R���X�g���N�^
	Time(int);							//�R���X�g���N�^�i�������Ԃ̐ݒ�t���j
	~Time();							//�f�X�g���N�^

	void SetLimit(int);					//�������Ԑݒ�
	void StartCount();					//�v���J�n
	void UpDate();						//�X�V
	void DrawLimitTime(int, int);		//�������ԕ`��

	bool GetIsLimit();					//�������Ԃ��߂�����

	void MinusLimitTime(int);			//�c��̐������Ԃ��}�C�i�X����

};

