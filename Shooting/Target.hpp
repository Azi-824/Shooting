//Target.hpp
//的の基になるクラス

#pragma once

//############### ヘッダファイル読み込み ##################
#include "Global.hpp"
#include "Image.hpp"
#include "Score.hpp"
#include "Time.hpp"
#include "Effect.hpp"

//############### マクロ定義 ####################
#define LIMIT_MIN	3	//制限時間の最小値
#define LIMIT_MAX	8	//制限時間の最大値

//############### 列挙型 ####################
enum TARGET_NAME
{
	TG_NAME_GHOST,	//お化け
	TG_NAME_BOMB1,	//爆弾1
	TG_NAME_ITEM	//アイテム
};

//############### クラス定義 ####################
class Target
{

private:

	int DrawX;		//描画X位置
	int DrawY;		//描画Y位置
	bool EventFlg;	//イベントフラグ

protected:

	Image* img;		//画像
	RECT rect;		//領域
	Time* time;		//時間
	Effect* effect;	//エフェクト
	int score;		//スコア

	void CommonEvent();	//共通のイベント処理
	void CreateDrawPos();	//描画位置を生成

public:

	Target();		//コンストラクタ
	~Target();		//デストラクタ

	virtual void UpDate();		//毎回行う処理
	virtual void SetInit(int);	//初期設定
	virtual void Event() = 0;	//的をクリックしたときのイベント
	bool OnClick();				//クリックしたか
	void Draw();				//描画
	bool GetEventFlg();			//イベントフラグ取得
	void SetEventFlg(bool);		//イベントフラグ設定

};
