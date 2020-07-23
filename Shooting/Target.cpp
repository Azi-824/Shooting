//Target.cpp
//的の基になるクラス

//################# ヘッダファイル読み込み ####################
#include "Target.hpp"

//################# クラス定義 ####################

//コンストラクタ
Target::Target()
{
	//メンバー初期化
	DrawX = 0;			//描画X位置
	DrawY = 0;			//描画Y位置
	score = 0;			//スコア
	img = new Image();	//画像
	time = new Time();	//時間
	rect = { 0,0,0,0 };	//領域
}

//デストラクタ
Target::~Target()
{
	delete img;	//img破棄
	delete time;//time破棄
}

//初期設定
void Target::SetInit(int score)
{
	img->SetInit();		//画像初期設定
	CreateDrawPos();	//描画位置生成
	//領域の設定
	rect.left = DrawX;						//左X
	rect.top = DrawY;						//左Y
	rect.right = DrawX + img->GetWidth();	//右X
	rect.bottom = DrawY + img->GetHeight();	//右Y
	this->score = score;	//スコア設定
	time->StartCount();		//計測開始
}

//描画位置生成
void Target::CreateDrawPos()
{
	int max_x = GAME_WIDTH - img->GetWidth();	//描画位置Xの最大値を設定
	int max_y = GAME_HEIGHT - img->GetHeight();	//描画位置Yの最大値を設定
	DrawX = GetRand(max_x);	//描画X位置設定
	DrawY = GetRand(max_y);	//描画Y位置設定
}

//描画
void Target::Draw()
{
	if (time->GetIsLimit())	//制限時間を越したら
	{
		img->SetIsDraw(false);	//描画をやめる
	}
	img->Draw(DrawX, DrawY);	//描画
}

//領域取得
RECT Target::GetRect()
{
	return rect;
}
