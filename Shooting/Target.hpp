//Target.hpp
//的の基になるクラス

#pragma once

//############### ヘッダファイル読み込み ##################
#include "Global.hpp"
#include "Image.hpp"
#include "Score.hpp"
#include "Time.hpp"

//############### マクロ定義 ####################

//############### 列挙型 ####################
enum TARGET_NAME
{
	TGNAME_GHOST,	//お化け
	TGNAME_BOMB1	//爆弾1
};

//############### クラス定義 ####################
class Target
{

private:

	int DrawX;		//描画X位置
	int DrawY;		//描画Y位置

	void CreateDrawPos();	//描画位置を生成

protected:

	Image* img;		//画像
	RECT rect;		//領域
	Time* time;		//時間
	int score;		//スコア

public:

	Target();		//コンストラクタ
	~Target();		//デストラクタ

	virtual void UpDate() = 0;	//毎回行う処理
	virtual void SetInit(int);	//初期設定
	virtual void Event() = 0;	//的をクリックしたときのイベント
	RECT GetRect();				//領域の取得
	void Draw();				//描画

};
