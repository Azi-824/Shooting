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
	return true;
}

//プレイ画面の処理
void Play::PlayScene()
{
	//****************************** 処理系 ********************************
	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		NowScene = SCENE_END;	//エンド画面へ
	}

	//***************************** 描画系 *********************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

}
