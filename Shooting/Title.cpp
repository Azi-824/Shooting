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
	back = new Image(IMG_DIR_BACK, IMG_NAME_TITLE);	//�w�i�摜����
	if (!back->GetIsLoad()) { return false; }		//�ǂݍ��ݎ��s
	return true;	//�ǂݍ��ݐ���
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
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��
}