//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Toy.hpp"
#include "Bomb.hpp"
#include "Item.hpp"

//############### �}�N����` #################
#define GAME_LIMIT_DRAW_X	680		//�Q�[���̐������ԕ`��X�ʒu
#define GAME_LIMIT_DRAW_Y	10		//�Q�[���̐������ԕ`��Y�ʒu
#define GAME_LIMIT_TIME		60		//�Q�[���̐�������

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
	Time* limit;				//��������

	bool StartFlg;	//Start()���s������

public:

	Play();		//�R���X�g���N�^
	~Play();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void Run() override;	//�v���C��ʂ̏���
	void Start();			//�V�[�����ς���Ĉ��ڂ����s������

};
