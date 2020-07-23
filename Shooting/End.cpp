//End.cpp
//エンド画面の処理

//############# ヘッダファイル読み込み ###############
#include "End.hpp"

//############# クラス定義 ################

//コンストラクタ
End::End()
{
	
}

//デストラクタ
End::~End()
{

}

//データ読込
bool End::DataLoad()
{
	return true;
}

//初期設定
void End::SetInit()
{
	//back->SetInit();	//背景画像初期設定
}


//エンド画面の処理
void End::PlayScene()
{
	//************************** 処理系 *********************************
	static bool IsInit = false;	//初期設定をしたか
	if (!IsInit)	//初期設定をしていなかったら
	{
		SetInit();	//初期設定
		IsInit = true;	//初期設定完了
	}

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		NowScene = SCENE_TITLE;	//タイトル画面へ
	}


	//**************************** 描画系 *******************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

}