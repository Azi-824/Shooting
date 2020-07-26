//Load.hpp
//読み込み画面のクラス（Sceneクラスから派生）

#pragma once

//################### ヘッダファイル読み込み #################
#include "Scene.hpp"

//################### マクロ定義 ###################
#define TEXT_DISCRIPTION	"画面に表示される的をクリックしよう！\n爆弾をクリックすると、\n時間が減ってしまうから気を付けよう！"

//################### クラス定義 ###################
class Load : public Scene	//Sceneクラスを継承
{
private:

	bool IsGameStart;	//ゲームスタートできるか

public:

	Load();	//コンストラクタ 
	~Load();				//デストラクタ

	void SetInit() override;	//初期設定
	bool DataLoad() override;	//データ読込
	void Run() override;	//ロード画面の処理

};
