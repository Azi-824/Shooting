//End.cpp
//�G���h��ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Ranking.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
Ranking::Ranking()
{
	
}

//�f�X�g���N�^
Ranking::~Ranking()
{

}

//�f�[�^�Ǎ�
bool Ranking::DataLoad()
{
	if (!bgm->Load(MUSIC_DIR_BGM, SE_NAME_BGM_RANKING)) { return false; }	//BGM�ǂݍ���
	return true;
}

//�����ݒ�
void Ranking::SetInit()
{
	//back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�

}


//�G���h��ʂ̏���
void Ranking::Run()
{
	//************************** �����n *********************************
	bgm->Play();	//BGM�𗬂�
	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
	}


	//**************************** �`��n *******************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��

}