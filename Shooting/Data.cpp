//Data.cpp
//データを管理するクラス

//################# ヘッダファイル読み込み ##################
#include "Data.hpp"

//################# クラス定義 ###################

//コンストラクタ
Data::Data(DATEDATA date, int score)
{
	//メンバー初期化
	this->date = date;	//データ
	Score = score;		//スコア
}

//コンストラクタ
Data::Data(int score)
{
	//メンバー初期化
	date = { 0 };		//データ
	GetDateTime(&date);	//データ取得
	Score = score;		//スコア
}

//デストラクタ
Data::~Data() {}

//日付データ設定
void Data::SetDate(DATEDATA date)
{
	this->date = date;
}

//スコア設定
void Data::SetScore(int score)
{
	Score = score;
}

//日付データ取得
DATEDATA Data::GetDate()
{
	return date;
}

//スコア取得
int Data::GetScore()
{
	return Score;
}
