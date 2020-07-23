//Bomb.cpp
//爆弾（マイナスの的）のクラス

//########## ヘッダファイル読み込み ##############
#include "Bomb.hpp"

//########## クラス定義 ############

//コンストラクタ 
Bomb::Bomb(Image* img)
{
	this->img = img;	//画像
}

//デストラクタ
Bomb::~Bomb(){}

//クリックされた時の処理
void Bomb::Event()
{
	DrawString(100, 300, "BombのEvent()", COLOR_WHITE);	//テスト用のテキストを描画
	Score::AddScore(score);	//スコア加算
}
