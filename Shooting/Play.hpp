//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Toy.hpp"
#include "Bomb.hpp"

//############### �}�N����` #################

using std::vector;

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

	vector<Target*> target;		//�I
	vector<Image*> tg_img;		//�I�̉摜
	vector<Effect*> tg_effect;	//�I�̃G�t�F�N�g
	vector<Animation*> eff_anim;//�A�j���[�V����
	vector<Music*> eff_se;		//���ʉ�

public:

	Play();		//�R���X�g���N�^
	~Play();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void Run() override;	//�v���C��ʂ̏���

};
