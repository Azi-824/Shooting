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
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_TITLE)) { return false; }	//背景画像読み込み
	return true;	//読み込み成功
}

//初期設定
void Title::SetInit()
{
	back->SetInit();	//背景画像初期設定
}


//タイトル画面の処理
void Title::PlayScene()
{

	//***************************** 処理系 ******************************
	static bool IsInit = false;	//初期設定をしたか
	if (!IsInit)	//初期設定をしていなかったら
	{
		SetInit();	//初期設定
		IsInit = true;	//初期設定完了
	}


	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		NowScene = SCENE_PLAY;	//プレイ画面へ
	}

	//****************************** 描画系 *****************************
	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画
}