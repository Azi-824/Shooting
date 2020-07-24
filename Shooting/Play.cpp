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
	for (auto e : tg_effect)
	{
		delete e;	//tg_effect�j��
	}
	vector<Effect*> v3;
	tg_effect.swap(v3);

	/*
	anim,se,��effect���Ŕj��
	effect��target���Ŕj�����Ă���
	*/
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
	//�A�j���[�V�����n
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_SHOT, ANIM_SHOT_ALL_CNT, ANIM_SHOT_YOKO_CNT, ANIM_SHOT_TATE_CNT,
		ANIM_SHOT_WIDTH, ANIM_SHOT_HEIGHT, ANIM_SHOT_SPEED, false));	//�e���A�j���[�V����
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_EXPLOSION, ANIM_EXPLOSION_ALL_CNT, ANIM_EXPLOSION_YOKO_CNT, ANIM_EXPLOSION_TATE_CNT,
		ANIM_EXPLOSION_WIDTH, ANIM_EXPLOSION_HEIGHT, ANIM_EXPLOSION_SPEED, false));	//�����A�j���[�V����
	for (auto a : eff_anim)
	{
		if (!a->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	}
	eff_se.push_back(new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_SHOT));			//�e�����ǉ�
	eff_se.push_back(new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_EXPLOSION));	//�������ǉ�
	for (auto s : eff_se)
	{
		if (!s->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	}
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_SHOT),eff_se.at(EF_NAME_SHOT)));				//�G�t�F�N�g�i�e���j�ǉ�
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_EXPLOSION), eff_se.at(EF_NAME_EXPLOSION)));	//�G�t�F�N�g�i�����j�ǉ�

	target.push_back(new Toy(tg_img.at(TGNAME_GHOST),tg_effect.at(EF_NAME_SHOT)));			//�ʂ�����݁i��������ǉ��j
	target.push_back(new Bomb(tg_img.at(TGNAME_BOMB1), tg_effect.at(EF_NAME_EXPLOSION)));	//���e1


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

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��

	//�I�֌W
	for (auto t : target)
	{
		t->Draw();	//�I�̕`��

		t->UpDate();//�X�V

		if (t->OnClick())	//�N���b�N���ꂽ��
		{
			t->SetEventFlg(true);	//�C�x���g�t���O
		}

	}

	if (Mouse::OnRightClick())	//�E�N���b�N������
	{
		NowScene = SCENE_END;	//�G���h��ʂ�
	}

}
