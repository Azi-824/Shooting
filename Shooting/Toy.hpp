//Toy.hpp
//的（プラスポイント）のクラス

#pragma once

//############## ヘッダファイル読み込み ################
#include "Target.hpp"

//############## マクロ定義 #################
#define IMG_TOY_DIR		R"(.\Image\Toy)"	//おもちゃの画像のディレクトリ

#define IMG_NAME_TOY01	R"(\toy01.png)"		//おもちゃ01の名前

//############## クラス定義 #################
class Toy : public Target	//Targetクラスを継承
{
public:

	Toy(Image*);		//コンストラクタ
	~Toy();				//デストラクタ

	void UpDate() override;	//毎回行う処理
	void Event() override;	//クリックされた時の処理

};
