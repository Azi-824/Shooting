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
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_TITLE)) { return false; }	//�w�i�摜�ǂݍ���
	if (!bgm->Load(MUSIC_DIR_BGM, SE_NAME_BGM_TITLE)) { return false; }	//BGM�ǂݍ���
	return true;	//�ǂݍ��ݐ���
}

//�����ݒ�
void Title::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�
}


//�^�C�g����ʂ̏���
void Title::Run()
{

	//***************************** �����n ******************************
	bgm->Play();	//BGM�𗬂�
	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_PLAY;	//�v���C��ʂ�
	}

	//****************************** �`��n *****************************
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��
}