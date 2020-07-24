//Animation.cpp
//アニメーションを管理するクラス

//################ ヘッダファイル読み込み ##################
#include "Animation.hpp"

//################ クラス定義 ##############

//コンストラクタ
/*
引　数：const char *：画像のディレクトリ
引　数：const char *：画像の名前
引　数：int：画像の総分割数
引　数：int：画像の横向きの分割数
引　数：int：画像の縦向きの分割数
引　数：int：画像の分割された横の大きさ
引　数：int：画像の分割された縦の大きさ
引　数：double：次の画像に変更する速さ
引　数：bool：アニメーションをループするかどうか
*/
Animation::Animation(const char* dir, const char* name, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed, bool IsLoop)
{
	//メンバー変数初期化
	IsLoad = false;			//読み込めたか？
	IsDrawEnd = false;		//描画終了したか?
	Width = 0;				//横幅を初期化
	Height = 0;				//高さを初期化

	//画像を読み込み
	string LoadfilePath;		//画像のファイルパスを作成
	LoadfilePath += dir;
	LoadfilePath += name;

	vector<int> work(SplitNumALL);	//分割読み込みで得たハンドルを格納する配列を総分割数で初期化
	/*
	後で修正を試す
	Handle.resize(SplitNumAll)
	*/

	//画像を分割して読み込み
	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SplitNumY, SplitWidth, SplitHeight, &work.front());
	Handle = work;

	if (Handle.front() == -1)	//画像が読み込めなかったとき
	{
		string ErrorMsg(ANIMATION_ERROR_MSG);		//エラーメッセージ作成
		ErrorMsg += TEXT('\n');						//改行
		ErrorMsg += LoadfilePath;					//画像のパス

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * を返す
			TEXT(ANIMATION_ERROR_TTILE),
			MB_OK);

		return;
	}

	ChangeMaxCnt = (GAME_FPS_SPEED * changeSpeed);
	ChangeCnt = 0;	//アニメーションするフレームのカウント

	NextChangeSpeed = changeSpeed;	//画像を変える速さ

	IsAnimeLoop = IsLoop;		//アニメーションがループするか

	Handle_itr = Handle.begin();	//先頭要素をイテレータに設定

	IsLoad = true;		//読み込めた

	//vectorのメモリ解放を行う
	vector<int> v;			//空のvectorを作成する
	work.swap(v);			//空と中身を入れ替える

	return;

}

//デストラクタ
Animation::~Animation()
{
	DeleteGraph(Handle.front());

	//vectorのメモリ解放を行う
	vector<int> v;			//空のvectorを作成する
	Handle.swap(v);			//空と中身を入れ替える

}

//幅を取得
int Animation::GetWidth()
{
	return Width;
}

//高さを取得
int Animation::GetHeight()
{
	return Height;
}

//読み込めた？
bool Animation::GetIsLoad(void)
{
	return IsLoad;
}

//描画終了したかどうか取得
bool Animation::GetIsDrawEnd()
{
	return IsDrawEnd;
}

//リセット
void Animation::Reset()
{
	IsDrawEnd = false;
}

//描画
/*
引数：int：Xの描画位置
引数：int：Yの描画位置
*/
void Animation::Draw(int x, int y)
{
	if (IsDrawEnd == false)	//アニメーションが終わっていなければ
	{
		DrawGraph(x, y, *Handle_itr, TRUE);	//イテレータ(ポインタ)を使用して描画
	}

	if (ChangeCnt == ChangeMaxCnt)	//次の画像を表示する時がきたら
	{
		//this->Handle.end()は、最後の要素の１個次のイテレータを返すので、-1している。
		if (Handle_itr == Handle.end() - 1)	//イテレータ(ポインタ)が最後の要素のときは
		{
			//アニメーションをループしないなら
			if (IsAnimeLoop == false)
			{
				IsDrawEnd = true;	//描画終了
			}

			//次回の描画に備えて、先頭の画像に戻しておく
			Handle_itr = Handle.begin();	//イテレータ(ポインタ)を要素の最初に戻す
		}
		else
		{
			++Handle_itr;	//次のイテレータ(ポインタ)(次の画像)に移動する
		}

		ChangeCnt = 0;	//カウント初期化
	}
	else
	{
		++ChangeCnt;	//カウントアップ
	}

}

//画面中央に描画
void Animation::DrawCenter()
{
	if (IsDrawEnd == false)	//アニメーションが終わっていなければ
	{
		DrawGraph((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), *Handle_itr, TRUE);	//イテレータ(ポインタ)を使用して描画
	}

	if (ChangeCnt == ChangeMaxCnt)	//次の画像を表示する時がきたら
	{
		//this->Handle.end()は、最後の要素の１個次のイテレータを返すので、-1している。
		if (Handle_itr == Handle.end() - 1)	//イテレータ(ポインタ)が最後の要素のときは
		{
			//アニメーションをループしないなら
			if (IsAnimeLoop == false)
			{
				IsDrawEnd = true;	//描画終了
			}

			//次回の描画に備えて、先頭の画像に戻しておく
			Handle_itr = Handle.begin();	//イテレータ(ポインタ)を要素の最初に戻す
		}
		else
		{
			++Handle_itr;	//次のイテレータ(ポインタ)(次の画像)に移動する
		}

		ChangeCnt = 0;	//カウント初期化
	}
	else
	{
		++ChangeCnt;	//カウントアップ
	}

}

