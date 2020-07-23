//Toy.cpp
//的（プラスポイント）のクラス

//############## ヘッダファイル読み込み ################
#include "Toy.hpp"

//############## クラス定義 ###################

//コンストラクタ
//引数:Image* : 的の画像
Toy::Toy(Image* img)
{
	this->img = img;	//画像
	time->SetLimit(5);	//制限時間設定
}

//デストラクタ
Toy::~Toy(){}

//クリックされた時の処理
void Toy::Event()
{
	DrawString(100, 300, "ToyのEvent()", COLOR_WHITE);	//テスト用のテキストを描画
	Score::AddScore(score);	//スコア加算
	
}