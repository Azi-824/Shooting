//Title.cpp
//�^�C�g����ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Title.hpp"

//############ �N���X��` ################

//�R���X�g���N�^
Title::Title()
{

}

//�f�X�g���N�^
Title::~Title()
{

}

//�f�[�^�Ǎ�
bool Title::DataLoad()
{
	return true;
}

//�^�C�g����ʂ̏���
void Title::PlayScene()
{
	//***************************** �����n ******************************
	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		NowScene = SCENE_PLAY;	//�v���C��ʂ�
	}

	//****************************** �`��n *****************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��
}