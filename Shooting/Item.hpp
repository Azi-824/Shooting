//Item.hpp
//アイテム（時間回復効果を持つ的）のクラス

#pragma once

//########### ヘッダファイル読み込み ############
#include "Target.hpp"

//########### マクロ定義 ##############
#define IMG_ITEM_DIR	R"(.\Image\Item)"	//アイテムの画像のディレクトリ

#define IMG_NAME_ITEM	R"(\item.png)"		//アイテムの名前

//########### クラス定義 ##############
class Item : public Target	//Targetを継承
{

public:

	Item(Image*, Effect*);		//コンストラクタ
	~Item();					//デストラクタ

	void UpDate() override;	//毎回行う処理
	void Event() override;	//クリックされた時の処理

};
