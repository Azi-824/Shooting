//Data.hpp
//データを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ###################
#include "Global.hpp"

//################### マクロ定義 #####################
#define RANKING_DRAW_X	10	//ランキング描画X位置
#define RANKING_DRAW_Y	10	//ランキング描画Y位置

//################### クラス定義 #####################
class Data
{

private:

	int Score;		//スコア
	int Element;	//要素番号
	static int ElementCnt;	//要素数

	DATEDATA date;	//日付データ


public:

	Data(DATEDATA,int);	//コンストラクタ
	Data(int);			//コンストラクタ
	~Data();			//デストラクタ

	void SetDate(DATEDATA);	//日付データ設定
	void SetScore(int);		//スコア設定

	DATEDATA GetDate();	//日付データ取得
	int GetScore();		//スコア取得

	void Draw();		//スコア描画

};
