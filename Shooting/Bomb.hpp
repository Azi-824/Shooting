//Bomb.hpp
//爆弾（マイナスの的）のクラス

#pragma once

//########### ヘッダファイル読み込み ##############
#include "Target.hpp"

//########### マクロ定義 #############
#define IMG_BOMB_DIR	R"(.\Image\Bomb)"	//爆弾の画像のディレクトリ

#define IMG_NAME_BOMB	R"(\bomb01.png)"	//爆弾01の名前

#define BOMB_TIME_VALUE		-10	//減らす時間

//########### クラス定義 #############
class Bomb : public Target	//Targetを継承
{
public:

	Bomb(Image*,Effect*);	//コンストラクタ
	~Bomb();				//デストラクタ

	void Event(Time*) override;	//クリックされた時の処理

};
