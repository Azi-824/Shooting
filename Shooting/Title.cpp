//Title.cpp
//タイトル画面の処理

//############# ヘッダファイル読み込み ##################
#include "Title.hpp"

//############ クラス定義 ################

//コンストラクタ
Title::Title()
{

}

//デストラクタ
Title::~Title()
{

}

//データ読込
bool Title::DataLoad()
{
	return true;
}

//タイトル画面の処理
void Title::PlayScene()
{
	//***************************** 処理系 ******************************
	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//エンターキーを押されたら
	{
		NowScene = SCENE_PLAY;	//プレイ画面へ
	}

	//****************************** 描画系 *****************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画
}