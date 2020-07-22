//Target.cpp
//的の基になるクラス

//################# ヘッダファイル読み込み ####################
#include "Target.hpp"

//################# クラス定義 ####################

//コンストラクタ
Target::Target(){}

//デストラクタ
Target::~Target()
{
	delete img;	//img破棄
}

//領域取得
RECT Target::GetRect()
{
	return rect;
}
