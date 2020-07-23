//Play.hpp
//プレイ画面の処理

#pragma once

//############### ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Toy.hpp"

//############### マクロ定義 #################

using std::vector;

//############### クラス定義 #################
class Play : public Scene	//Sceneクラスを継承
{
private:

	vector<Target*> target;	//的
	vector<Image*> tg_img;	//的の画像

public:

	Play();		//コンストラクタ
	~Play();			//デストラクタ

	void SetInit() override;	//初期設定
	bool DataLoad() override;	//データ読込
	void PlayScene() override;	//プレイ画面の処理

};
