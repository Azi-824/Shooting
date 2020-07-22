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
protected:

	Image* img;		//画像
	RECT rect;		//領域

public:

	Target();		//コンストラクタ
	~Target();		//デストラクタ

	virtual void Event() = 0;	//的をクリックしたときのイベント(後からスコアクラスを受け取り、Event()内でスコア加算をするように変更)
	RECT GetRect();				//領域の取得

	/*
	マウスクラスに追加
	bool OnClick(RECT);	//渡された領域内をクリックしたか判定
	*/
};
