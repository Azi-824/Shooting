//Effect.cpp
//エフェクトクラス

//################## ヘッダファイル読み込み ##################
#include "Effect.hpp"

//################## クラス定義 #######################

//コンストラクタ
//引数:Animation* :アニメーション
//引数:Music* :効果音
Effect::Effect(Animation* anim,Music* se)
{
	//メンバー初期化
	IsFadein = false;	//フェードインするか
	IsFadeout = false;	//フェードアウトするか

	this->anim = anim;	//アニメーション
	this->se = se;		//効果音
}

//コンストラクタ
Effect::Effect()
{
	//メンバー初期化
	IsFadein = false;	//フェードインするか
	IsFadeout = false;	//フェードアウトするか
}

//デストラクタ
Effect::~Effect()
{

	delete anim;	//anim破棄
	delete se;		//se破棄

}

//エフェクトを設定
//引数:Animation* :アニメーション
//引数:Music* :効果音
void Effect::SetEffect(Animation* anim,Music* se)
{
	this->anim = anim;
	this->se = se;
}

//描画
/*
引数：int：Xの描画位置
引数：int：Yの描画位置
*/
void Effect::Draw(int x, int y)
{
	anim->Draw(x, y);	//アニメーション描画
	se->PlayOne(false);	//効果音再生
}

//画面中央に描画
void Effect::DrawCenter()
{
	anim->DrawCenter();	//アニメーション描画
	se->PlayOne(false);	//効果音再生
}

//指定された領域内の中央に描画
void Effect::DrawCenter(RECT rect)
{
	anim->DrawCenter(rect);	//アニメーション描画
	se->PlayOne(false);	//効果音再生
}

//初期設定
void Effect::SetInit(void)
{
	anim->SetInit();	//アニメーション初期設定
	se->SetInit(DX_PLAYTYPE_BACK, 30);		//初期設定
}

//エフェクト終了したか取得
bool Effect::GetIsEffectEnd()
{
	return anim->GetIsDrawEnd();
}

//リセット
void Effect::Reset()
{
	anim->Reset();	//アニメーションリセット
	se->Reset();//効果音リセット
}

//フェードアウトをするか設定
void Effect::SetIsFadeout(bool isfadeout)
{
	IsFadeout = isfadeout;
	return;
}

//フェードインをするか設定
void Effect::SetIsFadein(bool isfadein)
{
	IsFadein = isfadein;
	return;
}

//フェードアウトエフェクト
//引数：int：透過させたい範囲のX位置
//引数：int：透過させたい範囲のY位置
//引数：int：透過させたい範囲の横幅
//引数：int：透過させたい範囲の高さ
//戻り値：bool：フェードアウトが終了したか
//true：終了：false：終了していない
bool Effect::FadeOut(int x, int y, int width, int height)
{

	static int cnt = 0;				//カウント用
	static bool end_flg = false;	//フェード終了フラグ

	if (IsFadeout)		//フェードアウトするとき
	{

		if (!end_flg)	//フェードアウト終了していなければ
		{
			//60フレーム分、待つ
			if (cnt < FADE_MAX_CNT)
			{
				++cnt;	//カウントアップ
			}
			else
			{
				end_flg = true;	//フェード終了
			}

			//フェードアウトの処理
			double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//透過%を計算
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//透過させる
			DrawBox(x, y, width, height, COLOR_BLACK, TRUE);						//真っ暗な画面にする
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる

		}
		else if (end_flg)	//フェードアウト終了したら
		{
			IsFadeout = false;	//フェードアウトしない
			cnt = 0;			//カウントリセット
			end_flg = false;	//終了フラグリセット
		}

	}
	else		//フェードアウトをしない時
	{
		cnt = 0;			//カウントリセット
		end_flg = false;	//終了フラグリセット
		return true;		//フェードアウトは終わっている
	}

	return end_flg;

}

//フェードインエフェクト
//引数：int：透過させたい範囲のX位置
//引数：int：透過させたい範囲のY位置
//引数：int：透過させたい範囲の横幅
//引数：int：透過させたい範囲の高さ
//戻り値：bool：フェードインが終了したか
//true：終了：false：終了していない
bool Effect::FadeIn(int x, int y, int width, int height)
{
	static int cnt = FADE_MAX_CNT;	//カウント用
	static bool end_flg = false;	//フェード終了フラグ

	if (IsFadein)		//フェードインするとき
	{

		if (!end_flg)	//フェードイン終了していなければ
		{
			//60フレーム分、待つ
			if (cnt > 0)
			{
				--cnt;	//カウントダウン
			}
			else
			{
				end_flg = true;	//フェード終了
			}

			//フェードインの処理
			double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//透過%を計算
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//透過させる
			DrawBox(x, y, width, height, COLOR_BLACK, TRUE);						//真っ暗な画面にする
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる

		}
		else if (end_flg)	//フェードイン終了したら
		{
			cnt = FADE_MAX_CNT;		//カウントリセット
			end_flg = false;		//エンドフラグリセット
			IsFadein = false;	//フェードインしない
		}

	}
	else		//フェードインをしない時
	{
		cnt = FADE_MAX_CNT;	//カウントリセット
		end_flg = false;	//終了フラグリセット
		return true;		//フェードインは終わっている
	}

	return end_flg;

}
