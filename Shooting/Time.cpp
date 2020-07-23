//Time.cpp
//時間を管理するクラス

//################## ヘッダファイル読み込み ################
#include "Time.hpp"

//################## クラス定義 ##################

//コンストラクタ
Time::Time()
{
	//メンバー変数初期化
	StartTime = 0;		//計測開始時間
	ElapsedTime = 0;	//経過時間
	LimitTime = 0;		//制限時間
	LimitInit = 0;		//制限時間の初期値
}

//コンストラクタ（制限時間の設定付き）
//引数：int：制限時間
Time::Time(int limit)
{
	//メンバー変数初期化
	StartTime = 0;		//計測開始時間
	ElapsedTime = 0;	//経過時間
	LimitTime = limit;	//制限時間を設定
	LimitInit = LimitTime;	//制限時間の初期値
}

//デストラクタ
Time::~Time() {}

//制限時間設定
void Time::SetLimit(int limit)
{
	LimitTime = limit;
	LimitInit = limit;
}

//計測開始
void Time::StartCount()
{
	//ミリ秒単位で取得するため、1/1000倍して、秒単位に変換する
	StartTime = GetNowCount() / 1000;	//計測開始時間設定
}

//更新
void Time::UpDate()
{
	//ミリ秒単位で取得するため、1/1000倍して、秒単位に変換する
	ElapsedTime = (GetNowCount() / 1000) - StartTime;	//経過時間を更新
	LimitTime = LimitInit - ElapsedTime;				//残りの時間を更新
}

//制限時間描画
//引数：int：描画X位置
//引数：int：描画Y位置
void Time::DrawLimitTime(int x, int y)
{
	UpDate();	//更新
	//DrawFormatStringToHandle(x, y, COLOR_WHITE, NowFontHandle ,"%d", LimitTime);	//制限時間を描画
	DrawFormatString(x, y, COLOR_WHITE, "%d", LimitTime);	//制限時間描画
}

//制限時間が過ぎたか取得
//戻り値:true 制限時間が過ぎている :false 制限時間が過ぎていない
bool Time::GetIsLimit()
{
	UpDate();	//更新
	return LimitTime <= 0 ? true : false;
}

//残りの制限時間をマイナスする
//引数：int：減らす時間（秒）
void Time::MinusLimitTime(int value)
{
	LimitTime -= value;	//制限時間を減らす
}
