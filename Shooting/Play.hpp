//Play.hpp
//プレイ画面の処理

#pragma once

//############### ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Toy.hpp"
#include "Bomb.hpp"

//############### マクロ定義 #################

using std::vector;

//############### クラス定義 #################
class Play : public Scene	//Sceneクラスを継承
{
private:

	vector<Target*> target;		//的
	vector<Image*> tg_img;		//的の画像
	vector<Effect*> tg_effect;	//的のエフェクト
	vector<Animation*> eff_anim;//アニメーション
	vector<Music*> eff_se;		//効果音

public:

	Play();		//コンストラクタ
	~Play();			//デストラクタ

	void SetInit() override;	//初期設定
	bool DataLoad() override;	//データ読込
	void Run() override;	//プレイ画面の処理

};
