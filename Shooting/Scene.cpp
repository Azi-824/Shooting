//Scene.cpp

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Scene.hpp"

//############## �N���X��` ################

int Scene::NowScene = 0;	//���݂̃V�[��

//�R���X�g���N�^
Scene::Scene()
{
	back = new Image();	//�C���X�^���X����
}

//�f�X�g���N�^
Scene::~Scene()
{
	delete back;	//back�j��
}

//���݂̃V�[�����擾
int Scene::GetNowScene()
{
	return NowScene;
}
