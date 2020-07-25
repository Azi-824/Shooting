//Scene.hpp
//各シーンの基になるクラス

#pragma once

//################### ヘッダファイル読み込み ######################
#include "Global.hpp"
#include "Image.hpp"
#include "Music.hpp"

//################### マクロ定義 #########################
//テキスト関係
#define LOAD_TEXT	"NowLoading…"		//ロード画面のテキスト
#define PUSH_TEXT	"PushEnter"			//エンターキーを押す、のテキスト
#define TITLE_TEXT	"NowTitle"			//タイトル画面のテキスト
#define PLAY_TEXT	"NowPlay"			//プレイ画面のテキスト
#define END_TEXT	"NowRanking"		//エンド画面のテキスト

//座標関係
#define TEST_TEXT_X	30					//テスト用のテキスト描画X位置
#define TEST_TEXT_Y	30					//テスト用のテキスト描画Y位置

//################### 列挙型 #####################
enum GAME_SCENE
{
	SCENE_LOAD,			//ロードシーン
	SCENE_TITLE,		//タイトルシーン
	SCENE_PLAY,			//プレイシーン
	SCENE_RANKING		//ランキングシーン
};

//################### クラス定義 #########################
class Scene
{
protected:

	//クラス共通
	static int NowScene;		//現在のシーン

	//インスタンス毎
	Image* back;	//背景画像
	Music* bgm;		//BGM

public:

	Scene();		//コンストラクタ
	~Scene();		//デストラクタ

	static int GetNowScene();	//現在のシーンを取得

	virtual void SetInit() = 0;		//初期設定
	virtual bool DataLoad() = 0;	//シーンごとの読み込み
	virtual void Run() = 0;			//シーン毎の処理

};
