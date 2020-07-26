//Play.cpp
//�v���C��ʂ̏���

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Play.hpp"

//################ �N���X��` ################

//�R���X�g���N�^
Play::Play()
{
	StartFlg = false;
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

	//BGM
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY)) { return false; }	//BGM�ǂݍ���

	//�I�֌W
	tg_img.push_back(new Image(IMG_TOY_DIR, IMG_NAME_TOY01));		//��������01
	tg_img.push_back(new Image(IMG_TOY_DIR, IMG_NAME_TOY02));		//��������02
	tg_img.push_back(new Image(IMG_TOY_DIR, IMG_NAME_TOY03));		//��������03
	tg_img.push_back(new Image(IMG_BOMB_DIR, IMG_NAME_BOMB01));		//���e1
	tg_img.push_back(new Image(IMG_BOMB_DIR, IMG_NAME_BOMB02));		//���e2
	tg_img.push_back(new Image(IMG_BOMB_DIR, IMG_NAME_BOMB03));		//���e3
	tg_img.push_back(new Image(IMG_ITEM_DIR, IMG_NAME_ITEM01));		//�A�C�e��1
	tg_img.push_back(new Image(IMG_ITEM_DIR, IMG_NAME_ITEM02));		//�A�C�e��2

	for (auto i : tg_img)
	{
		if (!i->GetIsLoad()) { return false; }
	}
	//�A�j���[�V�����n
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_SHOT, ANIM_SHOT_ALL_CNT, ANIM_SHOT_YOKO_CNT, ANIM_SHOT_TATE_CNT,
		ANIM_SHOT_WIDTH, ANIM_SHOT_HEIGHT, ANIM_SHOT_SPEED, false));	//�e���A�j���[�V����
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_SHOT, ANIM_SHOT_ALL_CNT, ANIM_SHOT_YOKO_CNT, ANIM_SHOT_TATE_CNT,
		ANIM_SHOT_WIDTH, ANIM_SHOT_HEIGHT, ANIM_SHOT_SPEED, false));	//�e���A�j���[�V����
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_SHOT, ANIM_SHOT_ALL_CNT, ANIM_SHOT_YOKO_CNT, ANIM_SHOT_TATE_CNT,
		ANIM_SHOT_WIDTH, ANIM_SHOT_HEIGHT, ANIM_SHOT_SPEED, false));	//�e���A�j���[�V����

	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_EXPLOSION, ANIM_EXPLOSION_ALL_CNT, ANIM_EXPLOSION_YOKO_CNT, ANIM_EXPLOSION_TATE_CNT,
		ANIM_EXPLOSION_WIDTH, ANIM_EXPLOSION_HEIGHT, ANIM_EXPLOSION_SPEED, false));	//�����A�j���[�V����
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_EXPLOSION, ANIM_EXPLOSION_ALL_CNT, ANIM_EXPLOSION_YOKO_CNT, ANIM_EXPLOSION_TATE_CNT,
		ANIM_EXPLOSION_WIDTH, ANIM_EXPLOSION_HEIGHT, ANIM_EXPLOSION_SPEED, false));	//�����A�j���[�V����
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_EXPLOSION, ANIM_EXPLOSION_ALL_CNT, ANIM_EXPLOSION_YOKO_CNT, ANIM_EXPLOSION_TATE_CNT,
		ANIM_EXPLOSION_WIDTH, ANIM_EXPLOSION_HEIGHT, ANIM_EXPLOSION_SPEED, false));	//�����A�j���[�V����

	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_ITEM, ANIM_ITEM_ALL_CNT, ANIM_ITEM_YOKO_CNT, ANIM_ITEM_TATE_CNT,
		ANIM_ITEM_WIDTH, ANIM_ITEM_HEIGHT, ANIM_ITEM_SPEED, false));	//�A�C�e���A�j���[�V����
	eff_anim.push_back(new Animation(ANIM_DIR, ANIM_NAME_ITEM, ANIM_ITEM_ALL_CNT, ANIM_ITEM_YOKO_CNT, ANIM_ITEM_TATE_CNT,
		ANIM_ITEM_WIDTH, ANIM_ITEM_HEIGHT, ANIM_ITEM_SPEED, false));	//�A�C�e���A�j���[�V����

	for (auto a : eff_anim)
	{
		if (!a->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	}

	//���ʉ�
	eff_se.push_back(new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_SHOT));			//�e�����ǉ�
	eff_se.push_back(new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_EXPLOSION));	//�������ǉ�
	eff_se.push_back(new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_ITEM));			//�A�C�e�����ǉ�
	for (auto s : eff_se)
	{
		if (!s->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	}

	//�G�t�F�N�g
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_SHOT01),eff_se.at(EF_SE_SHOT)));				//�G�t�F�N�g�i�e���j�ǉ�
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_SHOT02), eff_se.at(EF_SE_SHOT)));			//�G�t�F�N�g�i�e���j�ǉ�
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_SHOT03), eff_se.at(EF_SE_SHOT)));			//�G�t�F�N�g�i�e���j�ǉ�

	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_EXPLOSION01), eff_se.at(EF_SE_EXPLOSION)));	//�G�t�F�N�g�i�����j�ǉ�
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_EXPLOSION02), eff_se.at(EF_SE_EXPLOSION)));	//�G�t�F�N�g�i�����j�ǉ�
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_EXPLOSION03), eff_se.at(EF_SE_EXPLOSION)));	//�G�t�F�N�g�i�����j�ǉ�

	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_ITEM01), eff_se.at(EF_SE_ITEM)));			//�G�t�F�N�g�i�A�C�e���j�ǉ�
	tg_effect.push_back(new Effect(eff_anim.at(EF_NAME_ITEM02), eff_se.at(EF_SE_ITEM)));			//�G�t�F�N�g�i�A�C�e���j�ǉ�


	//�I
	target.push_back(new Toy(tg_img.at(TG_NAME_TOY01),tg_effect.at(EF_NAME_SHOT01)));			//��������01
	target.push_back(new Toy(tg_img.at(TG_NAME_TOY02), tg_effect.at(EF_NAME_SHOT02)));			//��������02
	target.push_back(new Toy(tg_img.at(TG_NAME_TOY03), tg_effect.at(EF_NAME_SHOT03)));			//��������03
	target.push_back(new Bomb(tg_img.at(TG_NAME_BOMB01), tg_effect.at(EF_NAME_EXPLOSION01)));	//���e1
	target.push_back(new Bomb(tg_img.at(TG_NAME_BOMB02), tg_effect.at(EF_NAME_EXPLOSION02)));	//���e2
	target.push_back(new Bomb(tg_img.at(TG_NAME_BOMB03), tg_effect.at(EF_NAME_EXPLOSION03)));	//���e3
	target.push_back(new Item(tg_img.at(TG_NAME_ITEM01), tg_effect.at(EF_NAME_ITEM01)));		//�A�C�e��1
	target.push_back(new Item(tg_img.at(TG_NAME_ITEM02), tg_effect.at(EF_NAME_ITEM02)));		//�A�C�e��2

	//���Ԍn
	limit = new Time(GAME_LIMIT_TIME);	//�Q�[���̐������Ԃ��Ǘ�����I�u�W�F�N�g�𐶐�

	return true;
}

//�����ݒ�
void Play::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�
	for (auto t : target)
	{
		t->SetInit();	//�����ݒ�
	}
}

//�v���C��ʂ̏���
void Play::Run()
{

	Start();	//�V�[�����ς������A��񂾂��s������

	bgm->Play();	//BGM�𗬂�
	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��
	Score::Draw();	//�X�R�A�`��

	//�I�֌W
	for (auto t : target)
	{
		t->Draw();	//�I�̕`��

		t->UpDate();//�X�V

		if (t->OnClick())	//�N���b�N���ꂽ��
		{
			t->SetEventFlg(true);	//�C�x���g�t���O
		}

		if (t->GetEventFlg())	//�C�x���g�t���O�������Ă�����
		{
			t->Event(limit);	//�C�x���g����
		}

	}

	//���Ԍn
	limit->UpDate();									//�X�V
	limit->Draw(GAME_LIMIT_DRAW_X, GAME_LIMIT_DRAW_Y);	//�`��
	if (limit->GetIsLimit())//�������Ԃ��߂�����
	{
		StartFlg = false;
		bgm->Stop();			//BGM���~�߂�
		data.push_back(new Data(Score::GetScore()));	//�f�[�^��ǉ�
		Save::Sort(&data);		//�\�[�g
		Save::DataSave(data);	//�Z�[�u
		NowScene = SCENE_RANKING;	//�G���h��ʂ�
	}

	if (Mouse::OnRightClick())	//�E�N���b�N������
	{
		StartFlg = false;
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_RANKING;	//�G���h��ʂ�
	}

}

//�V�[�����ς����1��ڂ����s������
void Play::Start()
{
	if (!StartFlg)
	{
		Score::Reset();			//�X�R�A���Z�b�g
		limit->StartCount();	//�������Ԃ̃J�E���g�X�^�[�g
		StartFlg = true;
	}
}
