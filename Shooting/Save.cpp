//Save.cpp
//セーブ関係のクラス

//################## ヘッダファイル読み込み ####################
#include "Save.hpp"

//################### クラス定義 ######################

//コンストラクタ
Save::Save(){}

//デストラクタ 
Save::~Save(){}

//読み込み
bool Save::Load(vector<Data*> *data)
{
	struct stat statbuf;			//ファイルの存在確認に使用
	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += SAVEDATA_NAME;
	if (stat(LoadFile.c_str(), &statbuf) == 0)		//セーブデータ用のファイルが作成されている場合
	{

		std::ifstream ifs(LoadFile.c_str());	//ファイル読み取り

		if (!ifs)		//ファイルオープン失敗時
		{
			string ErrorMsg(DATA_ERROR_MSG);	//エラーメッセージ作成
			ErrorMsg += TEXT('\n');				//改行
			ErrorMsg += LoadFile;				//画像のパス

			MessageBox(
				NULL,
				ErrorMsg.c_str(),	//char * を返す
				TEXT(DATA_ERROR_TTILE),
				MB_OK);

			return false;	//読み込み失敗

		}

		string buf;
		int sc = 0;		//スコア
		int cnt = 0;	//カウント用
		DATEDATA date;	//日付データ

		while (!ifs.eof())				//最後の行まで読み込み
		{
			std::getline(ifs, buf, ',');	//カンマまで読み込み
			date.Year = atoi(buf.c_str());	//年読み込み

			std::getline(ifs, buf, ',');	//カンマまで読み込み
			date.Mon = atoi(buf.c_str());	//月読み込み

			std::getline(ifs, buf, ',');	//カンマまで読み込み
			date.Day = atoi(buf.c_str());	//日読み込み

			std::getline(ifs, buf, '\n');	//改行まで読み込み
			sc = atoi(buf.c_str());			//スコア読み込み


			data->push_back(new Data(date, sc));		//データ追加
		}

	}

	return true;	//読み込み成功
}

//セーブ
bool Save::DataSave(vector<Data*> data)
{

	struct stat statbuf;			//ファイルの存在確認に使用
	if (stat(SAVEDATA_DIR, &statbuf) != 0)		//セーブデータ用のファイルが作成されていない場合
	{
		_mkdir(SAVEDATA_DIR);	//セーブデータを格納するフォルダを作成
	}

	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += SAVEDATA_NAME;

	std::ofstream ofs(LoadFile.c_str(), std::ios_base::ate);	//ファイルオープン

	if (!ofs)		//ファイルオープン失敗時
	{
		string ErrorMsg(DATA_ERROR_MSG);	//エラーメッセージ作成
		ErrorMsg += TEXT('\n');						//改行
		ErrorMsg += LoadFile;					//画像のパス

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * を返す
			TEXT(DATA_ERROR_TTILE),
			MB_OK);

		return false;		//セーブ失敗

	}

	Sort(&data);	//ソート処理

	vector<DATEDATA> date;	//日付データ
	vector<int>	score;		//スコア
	for (auto d : data)
	{
		date.push_back(d->GetDate());	//日付データをコピー
		score.push_back(d->GetScore());	//スコアをコピー
	}

	//セーブデータを書き込む
	for (int i = 0; i < SAVE_MAX; ++i)	//保存する最大数までループ
	{

		if (i >= data.size())	//データの個数に達したら
			break;

		ofs << date.at(i).Year << ',';	//年、書き出し
		ofs << date.at(i).Mon << ',';	//月、書き出し
		ofs << date.at(i).Day << ',';	//日、書き出し
		if (i == data.size() - 1)		//最後の書き込みだったら
		{
			//終端文字を付ける
			ofs << score.at(i) << '\0';			//スコア、書き出し
		}
		else	//最後の書き込みじゃなければ
		{
			//改行する
			ofs << score.at(i) << '\n';			//スコア、書き出し
		}

	}

	//vectorの解放
	vector<DATEDATA> v;	
	date.swap(v);
	vector<int>	v2;
	score.swap(v2);

	return true;	//セーブ成功
}

//ソート処理
void Save::Sort(vector<Data*> *data)
{
	for (int i = 0; i < data->size(); ++i)
	{
		for (int j = data->size() - 1; j > i; --j)
		{
			if (data->at(j)->GetScore() > data->at(j - 1)->GetScore())
			{
				auto temp = data->at(j);
				data->at(j) = data->at(j - 1);
				data->at(j - 1) = temp;
			}
		}
	}
}
