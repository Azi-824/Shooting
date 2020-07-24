//Play.cpp
//プレイ画面の処理

//################# ヘッダファイル読み込み #################
#include "Play.hpp"

//################ クラス定義 ################

//コンストラクタ
Play::Play()
{

}

//デストラクタ
Play::~Play()
{
	for (auto t : target)
	{
		delete t;	//target破棄
	}
	//vectorの解放
	vector<Target*> v;
	target.swap(v);

	for (auto i : tg_img)
	{
		delete i;	//tg_img破棄
	}
	//vectorの解放
	vector<Image*> v2;
	tg_img.swap(v2);
	for (auto e : tg_effect)
	{
		delete e;	//tg_effect破棄
	}
	vector<Effect*> v3;
	tg_effect.swap(v3);

	/*
	anim,se,はeffect内で破棄
	effectはtarget内で破棄している
	*/
}

//データ読込
bool Play::DataLoad()
{
	//画像関係
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { return false; }	//背景画像読み込み

	//的関係
	tg_img.push_back(new Image(IMG_TOY_DIR, IMG_NAME_TOY01));	//ぬいぐるみ（お化けを追加）
	tg_img.push_back(new Image(IMG_BOMB_DIR, IMG_NAME_BOMB01));	//爆弾1
	for (auto i : tg_img)
	{
		if (!i->GetIsLoad()) { return false; }
	}
	//アニメーション系
	anim = new Animation(ANIMATION_DIR, ANIMATION_NAME_EXPLOSION, ANIM_EXPLOSION_ALL_CNT, ANIM_EXPLOSION_YOKO_CNT, ANIM_EXPLOSION_TATE_CNT,
		ANIM_EXPLOSION_WIDTH, ANIM_EXPLOSION_HEIGHT, ANIM_EXPLOSION_SPEED, false);
	if (!anim->GetIsLoad()) { return false; }	//読み込み失敗
	se = new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_EXPLOSION);	//爆発音追加
	if (!se->GetIsLoad()) { return false; }	//読み込み失敗
	tg_effect.push_back(new Effect(anim,se));		//エフェクト（爆発）追加

	target.push_back(new Toy(tg_img.at(TGNAME_GHOST),tg_effect.at(0)));		//ぬいぐるみ（お化けを追加）
	target.push_back(new Bomb(tg_img.at(TGNAME_BOMB1), tg_effect.at(0)));	//爆弾1


	return true;
}

//初期設定
void Play::SetInit()
{
	back->SetInit();	//背景画像初期設定
	for (auto t : target)
	{
		t->SetInit(100);	//初期設定
	}
}

//プレイ画面の処理
void Play::Run()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

	//的関係
	for (auto t : target)
	{
		t->Draw();	//的の描画

		t->UpDate();//更新

		if (t->OnClick())	//クリックされたら
		{
			t->SetEventFlg(true);	//イベントフラグ
		}

	}

	if (Mouse::OnRightClick())	//右クリックしたら
	{
		NowScene = SCENE_END;	//エンド画面へ
	}

}
