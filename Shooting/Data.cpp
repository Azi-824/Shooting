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

	string str;	//描画文字列
	str = std::to_string(date.Year) + "年";	//年
	str += std::to_string(date.Mon) + "月";	//月
	str += std::to_string(date.Day) + "日";	//日
	str += std::to_string(Score) + "点";	//点

	if (Element == 0)	//先頭の時は
		DrawStringToHandle(RANKING_DRAW_X, RANKING_DRAW_Y, RANK_INDEX_TEXT, COLOR_WHITE, Font::GetNowHandle(), COLOR_BLACK);	//表題描画
	int height = GetFontSizeToHandle(Font::GetNowHandle());	//高さ取得
	DrawStringToHandle(RANKING_DRAW_X, (RANKING_DRAW_Y + height) * (Element + 1), str.c_str(), COLOR_WHITE, Font::GetNowHandle(), COLOR_BLACK);

}
