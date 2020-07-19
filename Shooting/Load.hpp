//Load.hpp
//読み込み画面のクラス（Sceneクラスから派生）

#pragma once

//################### ヘッダファイル読み込み #################
#include "Scene.hpp"

//################### マクロ定義 ###################

//################### クラス定義 ###################
class Load : public Scene	//Sceneクラスを継承
{
private:

	bool IsLoad;	//読み込めたか

public:

	Load();		//コンストラクタ 
	~Load();	//デストラクタ

	bool DataLoad() override;	//データ読込
	void PlayScene() override;	//ロード画面の処理

};
