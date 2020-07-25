//Button.cpp
//ボタンのクラス

//############### ヘッダファイル読み込み ###################
#include "Button.hpp"

//############### クラス定義 ###############

int Button::ElementCnt = 0;	//要素数

//コンストラクタ
Button::Button(Image* img)
{
	this->img = img;
	rect = { 0 };	//領域初期化
	Element = ElementCnt++;	//要素番号設定
}

//デストラクタ
Button::~Button()
{
	delete img;	//img破棄
}

//初期設定
void Button::SetInit(int x,int y)
{
	img->SetInit();	//画像初期設定
	//領域設定
	rect.left = x;						//左上X
	rect.top = y;						//左上Y
	rect.right = x + img->GetWidth();	//右下X
	rect.bottom = y + img->GetHeight();	//右下Y
}

//ボタンをクリックされたか
bool Button::OnClick()
{
	return Mouse::OnLeftClick(rect);
}

//描画
void Button::Draw()
{
	img->Draw(rect.left, rect.top);
}

//要素番号取得
int Button::GetElement()
{
	return Element;
}
