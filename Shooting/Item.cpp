//Item.cpp
//アイテム（時間回復効果を持つ的）のクラス

//######## ヘッダファイル読み込み ############
#include "Item.hpp"

//########### クラス定義 ##############

//コンストラクタ
//引数:Image* : 的の画像
//引数:Effect* :エフェクト
Item::Item(Image* img, Effect* effect)
{
	this->img = img;		//画像
	this->effect = effect;	//エフェクト
	time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//制限時間設定
}

//デストラクタ
Item::~Item() {}

//毎回行う処理
void Item::UpDate()
{
	if (time->GetIsLimit())	//制限時間を超えたか
	{
		/*
		描画しているときは、描画を消す
		描画していない時は、次の描画までの時間が過ぎたときのため、再描画する
		*/
		img->SetIsDraw(!img->GetIsDraw());	//現在の描画状態の逆を設定
		CreateDrawPos();					//描画位置再生成
		time->SetLimit(GetRand((LIMIT_MAX - LIMIT_MIN) + LIMIT_MIN));	//制限時間設定
		time->StartCount();	//計測開始
	}

	if (GetEventFlg())	//イベントフラグが立っているとき
	{
		Event();	//イベント処理
	}
}

//クリックされた時の処理
void Item::Event()
{
	DrawString(100, 300, "ItemのEvent()", COLOR_WHITE);	//テスト用のテキストを描画
	CommonEvent();	//共通のイベント処理
}
