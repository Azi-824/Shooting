//Time.cpp
//���Ԃ��Ǘ�����N���X

//################## �w�b�_�t�@�C���ǂݍ��� ################
#include "Time.hpp"

//################## �N���X��` ##################

//�R���X�g���N�^
Time::Time()
{
	//�����o�[�ϐ�������
	StartTime = 0;		//�v���J�n����
	ElapsedTime = 0;	//�o�ߎ���
	LimitTime = 0;		//��������
	LimitInit = 0;		//�������Ԃ̏����l
}

//�R���X�g���N�^�i�������Ԃ̐ݒ�t���j
//�����Fint�F��������
Time::Time(int limit)
{
	//�����o�[�ϐ�������
	StartTime = 0;		//�v���J�n����
	ElapsedTime = 0;	//�o�ߎ���
	LimitTime = limit;	//�������Ԃ�ݒ�
	LimitInit = LimitTime;	//�������Ԃ̏����l
}

//�f�X�g���N�^
Time::~Time() {}

//�������Ԑݒ�
void Time::SetLimit(int limit)
{
	LimitTime = limit;
	LimitInit = limit;
}

//�v���J�n
void Time::StartCount()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	StartTime = GetNowCount() / 1000;	//�v���J�n���Ԑݒ�
}

//�X�V
void Time::UpDate()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	ElapsedTime = (GetNowCount() / 1000) - StartTime;	//�o�ߎ��Ԃ��X�V
	LimitTime = LimitInit - ElapsedTime;				//�c��̎��Ԃ��X�V
}

//�������ԕ`��
//�����Fint�F�`��X�ʒu
//�����Fint�F�`��Y�ʒu
void Time::DrawLimitTime(int x, int y)
{
	UpDate();	//�X�V
	//DrawFormatStringToHandle(x, y, COLOR_WHITE, NowFontHandle ,"%d", LimitTime);	//�������Ԃ�`��
	DrawFormatString(x, y, COLOR_WHITE, "%d", LimitTime);	//�������ԕ`��
}

//�������Ԃ��߂������擾
//�߂�l:true �������Ԃ��߂��Ă��� :false �������Ԃ��߂��Ă��Ȃ�
bool Time::GetIsLimit()
{
	UpDate();	//�X�V
	return LimitTime <= 0 ? true : false;
}

//�c��̐������Ԃ��}�C�i�X����
//�����Fint�F���炷���ԁi�b�j
void Time::MinusLimitTime(int value)
{
	LimitTime -= value;	//�������Ԃ����炷
}
