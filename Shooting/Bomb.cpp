//Bomb.cpp
//爆弾（マイナスの的）のクラス

//########## ヘッダファイル読み込み ##############
#include "Bomb.hpp"

//########## クラス定義 ############

//コンストラクタ 
Bomb::Bomb(Image* img)
{
	this->img = img;	//画像
	time->SetLimit(8);	//制限時間設定
}

//デストラクタ
Bomb::~Bomb(){}

//毎回行う処理
void Bomb::UpDate()
{
	if (time->GetIsLimit())	//制限時間を超えたか
	{
		/*
		描画しているときは、描画を消す
		描画していない時は、次の描画までの時間が過ぎたときのため、再描画する
		*/
		img->SetIsDraw(!img->GetIsDraw());	//現在の描画状態の逆を設定
		time->StartCount();	//計測開始
	}
}

//クリックされた時の処理
void Bomb::Event()
{
	DrawString(100, 300, "BombのEvent()", COLOR_WHITE);	//テスト用のテキストを描画
	Score::AddScore(score);	//スコア加算
}
