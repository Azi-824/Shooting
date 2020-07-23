//Load.cpp
//���[�h��ʂ̃N���X

//############## �w�b�_�t�@�C���ǂݍ��� #################
#include "Load.hpp"

//############## �N���X��` ################

//�R���X�g���N�^
Load::Load()
{
	//�����o�[������
	IsGameStart = false;	//�Q�[���X�^�[�g�ł��邩
}

//�f�X�g���N�^
Load::~Load(){}

//�����ݒ�
void Load::SetInit(){}

//�f�[�^�Ǎ�
bool Load::DataLoad()
{
	return true;
}

//�ǂݍ��݉�ʂ̏���
void Load::Run()
{
	//***************************** �����n ************************************
	if (IsGameStart)	//�Q�[���X�^�[�g�ł���Ȃ�
	{
		if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
		{
			NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
		}

	}

	if (GetASyncLoadNum() == 0)	//�񓯊��œǂݍ���ł��鏈�����I�������
	{

		SetUseASyncLoadFlag(FALSE);	//�����ǂݍ��݂ɐݒ�

		IsGameStart = true;		//�Q�[���X�^�[�g�ł���
	}

	//********************************* �`��n ************************************
	if (IsGameStart)	//�Q�[���X�^�[�g�ł���Ȃ�
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, GetColor(255, 255, 255));	//�v�b�V���A�̃e�L�X�g��`��
	}
	else		//�ł��Ȃ��Ȃ�
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, GetColor(255, 255, 255));	//�ǂݍ��ݒ��̃e�L�X�g��`��
	}


}
