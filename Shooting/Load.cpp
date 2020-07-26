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
	if (!Save::Load(&data)) { return false; }	//�Z�[�u�f�[�^�ǂݍ��ݎ��s
	font.push_back(new Font(F_NAME_HGS, F_SIZE_NORMAL, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));	//�t�H���g(�ʏ�T�C�Y����)
	font.push_back(new Font(F_NAME_HGS, F_SIZE_MINI, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING));		//�t�H���g(�~�j�T�C�Y����)
	font.push_back(new Font(F_NAME_HGS, F_SIZE_RANKING, F_BOLD_NORMAL, DX_FONTTYPE_ANTIALIASING_EDGE_4X4,-1,F_EDGE_SIZE));	//�t�H���g(�����L���O�p�T�C�Y����)
	for (auto f : font)
	{
		if (!f->GetIsCreate()) { return false; }	//�ǂݍ��ݎ��s
	}
	font.at(FH_NORMAL)->Chenge();	//�ʏ�T�C�Y�̃t�H���g�ɕύX
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
	//if (IsGameStart)	//�Q�[���X�^�[�g�ł���Ȃ�
	//{
	//	DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, GetColor(255, 255, 255), Font::GetNowHandle());
	//}
	//else		//�ł��Ȃ��Ȃ�
	//{
	//	DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, GetColor(255, 255, 255), Font::GetNowHandle());
	//}
	font.at(FH_MINI)->Chenge();	//�t�H���g�ύX
	DrawStringToHandle(TEST_TEXT_X, TEST_TEXT_Y, TEXT_DISCRIPTION, GetColor(255, 255, 255), Font::GetNowHandle());
	font.at(FH_NORMAL)->Chenge();	//�t�H���g�ύX

}
