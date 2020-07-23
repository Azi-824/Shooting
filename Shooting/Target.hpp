//Target.hpp
//的の基になるクラス

#pragma once

//############### ヘッダファイル読み込み ##################
#include "Global.hpp"
#include "Image.hpp"

//############### マクロ定義 ####################

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
	int Score;		//スコア

public:

	Target();		//コンストラクタ
	~Target();		//デストラクタ

	virtual void SetInit(int);	//初期設定
	virtual void Event() = 0;	//的をクリックしたときのイベント(後からスコアクラスを受け取り、Event()内でスコア加算をするように変更)
	RECT GetRect();				//領域の取得
	void Draw();				//描画

};
