//Item.hpp
//アイテム（時間回復効果を持つ的）のクラス

#pragma once

//########### ヘッダファイル読み込み ############
#include "Target.hpp"

//########### マクロ定義 ##############
#define IMG_ITEM_DIR	R"(.\Image\Item)"	//アイテムの画像のディレクトリ

#define IMG_NAME_ITEM	R"(\item.png)"		//アイテムの名前

#define ITEM_TIME_VALUE	5	//増やす時間

//########### クラス定義 ##############
class Item : public Target	//Targetを継承
{

public:

	Item(Image*, Effect*);		//コンストラクタ
	~Item();					//デストラクタ

	void Event(Time*) override;	//クリックされた時の処理

};
