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
	for (auto t : target)
	{
		delete t;	//target�j��
	}
	//vector�̉��
	vector<Target*> v;
	target.swap(v);

	for (auto i : tg_img)
	{
		delete i;	//tg_img�j��
	}
	//vector�̉��
	vector<Image*> v2;
	tg_img.swap(v2);
}

//�f�[�^�Ǎ�
bool Play::DataLoad()
{
	//�摜�֌W
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { return false; }	//�w�i�摜�ǂݍ���

	//�I�֌W
	tg_img.push_back(new Image(IMG_TOY_DIR, IMG_NAME_TOY01));	//�ʂ�����݁i��������ǉ��j
	tg_img.push_back(new Image(IMG_BOMB_DIR, IMG_NAME_BOMB01));	//���e1
	for (auto i : tg_img)
	{
		if (!i->GetIsLoad()) { return false; }	
	}
	target.push_back(new Toy(tg_img.at(TGNAME_GHOST)));		//�ʂ�����݁i��������ǉ��j
	target.push_back(new Bomb(tg_img.at(TGNAME_BOMB1)));	//���e1

	return true;
}

//�����ݒ�
void Play::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	for (auto t : target)
	{
		t->SetInit(100);	//�����ݒ�
	}
}

//�v���C��ʂ̏���
void Play::Run()
{
	//****************************** �����n ********************************
	for (auto t : target)
	{
		t->UpDate();//�X�V

		if (t->OnClick())	//�N���b�N���ꂽ��
		{
			t->Event();		//�C�x���g����
		}

	}
	if (Mouse::OnRightClick())	//�E�N���b�N������
	{
		NowScene = SCENE_END;	//�G���h��ʂ�
	}


	//***************************** �`��n *********************************
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��
	for (auto t : target)
	{
		t->Draw();	//�I�̕`��
	}
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��

}
