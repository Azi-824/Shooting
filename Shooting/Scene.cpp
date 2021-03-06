//Scene.cpp

//############# ヘッダファイル読み込み ###############
#include "Scene.hpp"

//############## クラス定義 ################

int Scene::NowScene = 0;	//現在のシーン
bool Scene::GameEnd = false;//ゲームエンドフラグ
vector<Data*> Scene::data;	//データ
vector<Font*> Scene::font;	//フォント

//コンストラクタ
Scene::Scene()
{
	back = new Image();	//インスタンス生成
	bgm = new Music();	//インスタンス生成
}

//デストラクタ
Scene::~Scene()
{
	delete back;	//back破棄
	delete bgm;		//bgm破棄
}

//現在のシーンを取得
int Scene::GetNowScene()
{
	return NowScene;
}

//ゲームエンドフラグを取得
bool Scene::IsGameEnd()
{
	return GameEnd;
}
