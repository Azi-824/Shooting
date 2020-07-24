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
	target.push_back(new Toy(tg_img.at(TGNAME_GHOST)));		//ぬいぐるみ（お化けを追加）
	target.push_back(new Bomb(tg_img.at(TGNAME_BOMB1)));	//爆弾1

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
	//****************************** 処理系 ********************************
	for (auto t : target)
	{
		t->UpDate();//更新

		if (t->OnClick())	//クリックされたら
		{
			t->Event();		//イベント処理
		}

	}
	if (Mouse::OnRightClick())	//右クリックしたら
	{
		NowScene = SCENE_END;	//エンド画面へ
	}


	//***************************** 描画系 *********************************
	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画
	for (auto t : target)
	{
		t->Draw();	//的の描画
	}
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

}
