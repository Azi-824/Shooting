//Play.cpp
//�v���C��ʂ̏���

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Play.hpp"

//################ �N���X��` ################

//�R���X�g���N�^
Play::Play()
{

}

//�f�X�g���N�^
Play::~Play()
{

}

//�f�[�^�Ǎ�
bool Play::DataLoad()
{
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { return false; }	//�w�i�摜�ǂݍ���
	return true;
}

//�v���C��ʂ̏���
void Play::PlayScene()
{
	//****************************** �����n ********************************
	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		NowScene = SCENE_END;	//�G���h��ʂ�
	}

	//***************************** �`��n *********************************
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��

}
