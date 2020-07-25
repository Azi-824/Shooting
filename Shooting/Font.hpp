//Font.hpp
//�t�H���g�N���X

/*
�ǉ����@
�E�t�H���g�̃t�@�C�����ƁA�t�H���g�̖��O���}�N����`����
�E�}�N����`����Ă���t�H���g�̎�ނ𑝂₷
�EAdd�������g�p���āA�Q�[�����Ŏg�p����t�H���g�𑝂₷���Ƃ��ł���
*/

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
#include <string>
#include <vector>

//################ �}�N����` �t�@�C���p�X�Ɩ��O ###############
#define FONT_DIR			R"(.\Font)"				//�t�H���g�t�@�C���̏ꏊ

#define FONT_FILE_NAME		R"(\HGRGY003.ttf)"			//�t�H���g�̖��O
//############### �}�N����` ##################

//*********** �t�H���g�� **************
#define FONT_NAME		"HGS�s����"					//�t�H���g�̐�������

//*********** �t�H���g�T�C�Y **************
#define F_SIZE_NORMAL	128			//�ʏ�̃t�H���g�T�C�Y
#define F_SIZE_MINI		90			//�t�H���g�T�C�Y�i�~�j�j
#define F_SIZE_RANKING	42			//�����L���O�`��̎��̃t�H���g�T�C�Y

//************* �t�H���g�̑��� *****************
#define F_BOLD_NORMAL	5			//�ʏ�̃t�H���g�̑���

//################ �}�N����` �G���[���b�Z�[�W #################
#define FONT_ERROR_TITLE "FONT_ERROR"						//�G���[�^�C�g��
#define FONT_ERROR_MSG	"�t�H���g���ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//################ �񋓌^ #####################
enum LOAD_FONT_NAME
{
	F_NAME_HGS	//HGS�s����
};	//�ǂݍ��񂾃t�H���g�̎��

enum FONT_HANDLE_TYPE
{
	FH_NORMAL,	//HGS�s���̂̃m�[�}���T�C�Y�̃n���h��
	FH_MINI,	//�~�j�T�C�Y�̃n���h��
	FH_RANKING	//�����΂�t�H���g�̃����L���O�`��T�C�Y�̃n���h��
};

using std::vector;
using std::string;

//################ �N���X�̒�` ##################
class Font {

private:
	static vector<string> FilePath;			//�p�X
	static vector<string> LoadFontName;		//�ǂݍ��񂾃t�H���g�̖��O

	int Handle;								//�t�H���g�n���h��
	bool IsCreate;							//�쐬�ł�����

	static int NowFont;						//���݂̃t�H���g�n���h��

	static bool LoadFont(const char*, const char*, const char*);	//�t�H���g��ǂݍ���

public:

	Font(int, int, int, int);		//�R���X�g���N�^
	~Font();	//�f�X�g���N�^

	static bool ReleaseFont();		//�ǂݍ��񂾃t�H���g���J��
	bool GetIsCreate();				//�쐬�ł������擾
	void Chenge();					//�t�H���g�n���h����ύX
	static int GetNowHandle();		//���݂̃n���h�����擾
};
