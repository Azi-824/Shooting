//Data.cpp
//データを管理するクラス

//################# ヘッダファイル読み込み ##################
#include "Data.hpp"

//################# クラス定義 ###################

int Data::ElementCnt = 0;	//要素数

//コンストラクタ
Data::Data(DATEDATA date, int score)
{
	//メンバー初期化
	this->date = date;	//データ
	Score = score;		//スコア
	Element = ElementCnt++;	//要素番号
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

//スコア描画
void Data::Draw()
{
	if (Element >= RANKING_DRAW_MAX)	//描画する最大数より多ければ
		return;	//描画せず終了

	if (Element == 0)	//先頭の時は
		DrawStringToHandle(RANKING_DRAW_X, RANKING_DRAW_Y, RANK_INDEX_TEXT, COLOR_GREEN, Font::GetNowHandle());	//表題描画
	int height = GetFontSizeToHandle(Font::GetNowHandle());	//高さ取得
	DrawFormatStringToHandle(RANKING_DRAW_X, (RANKING_DRAW_Y + height) * (Element + 1), COLOR_GREEN, Font::GetNowHandle(),"%d年 %d月 %d日 %d点", date.Year, date.Mon, date.Day, Score, COLOR_WHITE);
}
