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
	//�摜�֌W
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_RANKING)) { return false; }	//�w�i�摜�ǂݍ���

	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_RANKING)) { return false; }	//BGM�ǂݍ���
	return true;
}

//�����ݒ�
void Ranking::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
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
	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��
	font.at(FH_RANKING)->Chenge();	//�t�H���g�n���h���ύX
	for (auto d : data)
	{
		d->Draw();	//�X�R�A�`��
	}
	font.at(FH_NORMAL)->Chenge();	//�t�H���g�n���h���ύX

}