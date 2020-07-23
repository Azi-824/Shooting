//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Toy.hpp"

//############### �}�N����` #################

using std::vector;

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

	vector<Target*> target;	//�I
	vector<Image*> tg_img;	//�I�̉摜

public:

	Play();		//�R���X�g���N�^
	~Play();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void PlayScene() override;	//�v���C��ʂ̏���

};
