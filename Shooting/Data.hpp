//Data.hpp
//データを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ###################
#include "Global.hpp"

//################### マクロ定義 #####################
#define DATA_MAX	10	//データの最大数

//################### クラス定義 #####################
class Data
{

private:

	int Score;		//スコア

	DATEDATA date;	//日付データ


public:

	Data(DATEDATA,int);	//コンストラクタ
	Data(int);			//コンストラクタ
	~Data();			//デストラクタ

	void SetDate(DATEDATA);	//日付データ設定
	void SetScore(int);		//スコア設定

	DATEDATA GetDate();	//日付データ取得
	int GetScore();		//スコア取得

};
