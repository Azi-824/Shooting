//Effect.hpp
//エフェクトを管理するクラス

#pragma once

//################### ヘッダファイル読み込み ######################
#include "Global.hpp"
#include "Animation.hpp"
#include "Music.hpp"

//###################### マクロ定義：ファイルパス、名前 ######################
#define EFFECT_DIR				R"(.\MY_EFFECT)"				//エフェクトの画像ファイルの場所

#define EFFECT_NAME_ATACK		R"(\Atack.png)"					//攻撃エフェクトの画像の名前

//###################### マクロ定義：エラーメッセージ ########################
#define EFFECT_ERROR_TTILE	"EFFECT_ERROR"						//エラータイトル
#define EFFECT_ERROR_MSG	"エフェクトが読み込めませんでした"	//エラーメッセージ

//###################### マクロ定義 #################################

//###################### 列挙型 ##########################

using std::vector;
using std::string;
//################### クラス定義 #########################
class Effect
{
private:

	Animation* anim;			//アニメーション
	Music* se;					//効果音

	bool IsFadeout;				//フェードアウト処理を行うか
	bool IsFadein;				//フェードイン処理を行うか

public:

	Effect(Animation*,Music*);	//コンストラクタ
	Effect();					//コンストラクタ
	~Effect();					//デストラクタ

	void SetEffect(Animation*,Music*);	//エフェクトを設定

	void Draw(int, int);	//描画
	void DrawCenter();		//画面中央に描画
	void DrawCenter(RECT);	//指定された領域内の中央に描画

	void SetInit();						//初期設定

	bool GetIsEffectEnd();				//エフェクト終了したか取得
	void Reset();						//リセット

	void SetIsFadeout(bool);			//フェードアウトをするか設定
	void SetIsFadein(bool);				//フェードインをするか設定

	bool FadeOut(int, int, int, int);	//フェードアウトエフェクト
	bool FadeIn(int, int, int, int);	//フェードインエフェクト

};
