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

}

//データ読込
bool Play::DataLoad()
{
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { return false; }	//背景画像読み込み
	return true;
}

//プレイ画面の処理
void Play::PlayScene()
{
	//****************************** 処理系 ********************************
	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		NowScene = SCENE_END;	//エンド画面へ
	}

	//***************************** 描画系 *********************************
	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

}
