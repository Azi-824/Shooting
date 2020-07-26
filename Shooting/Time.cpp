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
	NowLimit = 0;		//�c��̐�������
	Limit = 0;			//��������
	LimitInit = 0;		//�������Ԃ̏����l
}

//�R���X�g���N�^�i�������Ԃ̐ݒ�t���j
//�����Fint�F��������
Time::Time(int limit)
{
	//�����o�[�ϐ�������
	StartTime = 0;		//�v���J�n����
	ElapsedTime = 0;	//�o�ߎ���
	NowLimit = limit;	//�c��̐�������
	Limit = limit;		//��������
	LimitInit = NowLimit;	//�������Ԃ̏����l
}

//�f�X�g���N�^
Time::~Time() {}

//�������Ԑݒ�
void Time::SetLimit(int limit)
{
	NowLimit = limit;
	LimitInit = limit;
}

//�v���J�n
void Time::StartCount()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	StartTime = GetNowCount() / 1000;	//�v���J�n���Ԑݒ�
	ElapsedTime = (GetNowCount() / 1000) - StartTime;	//�o�ߎ��Ԃ�ݒ�
	Limit = LimitInit;	//�������ԏ�����
	NowLimit = Limit;	//�c��̐������Ԑݒ�
}

//�X�V
void Time::UpDate()
{
	//�~���b�P�ʂŎ擾���邽�߁A1/1000�{���āA�b�P�ʂɕϊ�����
	ElapsedTime = (GetNowCount() / 1000) - StartTime;	//�o�ߎ��Ԃ��X�V
	NowLimit = Limit - ElapsedTime;						//�c��̎��Ԃ��X�V
}

//�������ԕ`��
//�����Fint�F�`��X�ʒu
//�����Fint�F�`��Y�ʒu
void Time::Draw(int x, int y)
{
	UpDate();	//�X�V
	DrawFormatStringToHandle(x, y, COLOR_BLACK, Font::GetNowHandle() ,"%d", NowLimit);	//�������Ԃ�`��
}

//�������Ԃ��߂������擾
//�߂�l:true �������Ԃ��߂��Ă��� :false �������Ԃ��߂��Ă��Ȃ�
bool Time::GetIsLimit()
{
	UpDate();	//�X�V
	return NowLimit <= 0 ? true : false;
}

//�n���ꂽ�l�̕����Ԃ����Z����
//�����Fint�F�����鎞�ԁi�b�j
void Time::Add(int value)
{
	Limit += value;	//���Ԃ�������
}
