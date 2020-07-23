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

//エンド画面の処理
void End::PlayScene()
{
	//************************** 処理系 *********************************
	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		NowScene = SCENE_TITLE;	//タイトル画面へ
	}


	//**************************** 描画系 *******************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

}