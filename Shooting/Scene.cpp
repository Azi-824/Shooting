//Scene.cpp

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Scene.hpp"

//############## �N���X��` ################

int Scene::NowScene = 0;	//���݂̃V�[��
vector<Data*> Scene::data;	//�f�[�^
vector<Font*> Scene::font;	//�t�H���g

//�R���X�g���N�^
Scene::Scene()
{
	back = new Image();	//�C���X�^���X����
	bgm = new Music();	//�C���X�^���X����
}

//�f�X�g���N�^
Scene::~Scene()
{
	delete back;	//back�j��
	delete bgm;		//bgm�j��
}

//���݂̃V�[�����擾
int Scene::GetNowScene()
{
	return NowScene;
}
