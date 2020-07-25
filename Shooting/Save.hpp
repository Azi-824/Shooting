//Save.hpp
//�Z�[�u�֌W�̃N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Global.hpp"
#include "Data.hpp"
#include <fstream>
#include <sys/stat.h>
#include <direct.h>

//################## �}�N����` #######################
#define SAVEDATA_DIR	R"(C:\Syateki)"		//�Z�[�u�f�[�^�̕ۑ��f�B���N�g����

#define SAVEDATA_NAME	R"(\Syateki.csv)"	//�Z�[�u�f�[�^�̖��O

#define SAVE_MAX		15	//�ۑ�����f�[�^�̍ő吔

//############## �}�N����`�F�G���[���b�Z�[�W ###################
#define DATA_ERROR_TTILE	"DATA_ERROR"						//�G���[�^�C�g��
#define DATA_ERROR_MSG		"�f�[�^���ǂݍ��߂܂���ł���"		//�G���[���b�Z�[�W

using std::string;
using std::vector;

//########### �N���X��` #############
class Save
{

private:

	static void Sort(vector<Data*>*);	//�\�[�g����

public:

	Save();		//�R���X�g���N�^
	~Save();	//�f�X�g���N�^

	static bool Load(vector<Data*>*);		//�ǂݍ���
	static bool DataSave(vector<Data*>);	//�Z�[�u

};
