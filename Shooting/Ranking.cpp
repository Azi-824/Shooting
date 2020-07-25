//End.cpp
//エンド画面の処理

//############# ヘッダファイル読み込み ###############
#include "Ranking.hpp"

//############# クラス定義 ################

//コンストラクタ
Ranking::Ranking()
{
	
}

//デストラクタ
Ranking::~Ranking()
{

}

//データ読込
bool Ranking::DataLoad()
{
	if (!bgm->Load(MUSIC_DIR_BGM, SE_NAME_BGM_RANKING)) { return false; }	//BGM読み込み
	return true;
}

//初期設定
void Ranking::SetInit()
{
	//back->SetInit();	//背景画像初期設定
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM初期設定

}


//エンド画面の処理
void Ranking::Run()
{
	//************************** 処理系 *********************************
	bgm->Play();	//BGMを流す
	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm->Stop();			//BGMを止める
		NowScene = SCENE_TITLE;	//タイトル画面へ
	}


	//**************************** 描画系 *******************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

}