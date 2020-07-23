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
}

//デストラクタ
Toy::~Toy(){}

//クリックされた時の処理
void Toy::Event()
{
	DrawString(100, 100, "ToyのEvent()", COLOR_WHITE);	//テスト用のテキストを描画
}