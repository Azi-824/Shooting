//Effect.hpp
//�G�t�F�N�g���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
//#include "Music.hpp"

//###################### �}�N����`�F�t�@�C���p�X�A���O ######################
#define EFFECT_DIR				R"(.\MY_EFFECT)"				//�G�t�F�N�g�̉摜�t�@�C���̏ꏊ

#define EFFECT_NAME_ATACK		R"(\Atack.png)"					//�U���G�t�F�N�g�̉摜�̖��O

//###################### �}�N����`�F�G���[���b�Z�[�W ########################
#define EFFECT_ERROR_TTILE	"EFFECT_ERROR"						//�G���[�^�C�g��
#define EFFECT_ERROR_MSG	"�G�t�F�N�g���ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//###################### �}�N����` #################################

//********************** �T�C�Y ************************
#define EFFECT_ATACK_WIDTH		240	//������
#define EFFECT_ATACK_HEIGHT		240	//��������


//********************** ������ **************************
#define EFFECT_ATACK_YOKO_CNT		7	//��������
#define EFFECT_ATACK_TATE_CNT		1	//�c������

//************************ �������� **************************
#define EFFECT_ATACK_ALL_CNT	EFFECT_ATACK_YOKO_CNT * EFFECT_ATACK_TATE_CNT	//��������

//************************ �`�摬�x ***************************
#define EFFECT_ATACK_SPEED		0.08

//###################### �񋓌^ ##########################
enum EFFECT_KIND
{
	EFFECT_ATACK		//�U���G�t�F�N�g
};

using std::vector;
using std::string;
//################### �N���X��` #########################
class Effect
{
private:

	vector<int> Handle;					//�n���h��
	vector<int>::iterator Handle_itr;	//�n���h���̃C�e���[�^

	//Music* Se;					//�G�t�F�N�g���ʉ�

	int Width;					//��
	int Height;					//����

	double NextChangeSpeed;		//�A�j���[�V������ύX���鑬��(�b)
	int ChangeCnt;						//�A�j���[�V��������t���[���̃J�E���g
	int ChangeMaxCnt;			//�A�j���[�V��������t���[���̍ő�l

	bool IsAnimeLoop;			//�A�j���[�V�����̓��[�v����H
	bool IsAnimeStop;			//�A�j���[�V�����̓X�g�b�v�������H
	bool IsDraw;				//�`�悵�Ă悢��

	bool IsDrawEnd;				//�`��I��������

	bool IsLoad;				//�ǂݍ��߂����H
	bool IsCreateSe;			//���ʉ��̃I�u�W�F�N�g���쐬������

	bool IsFadeout;				//�t�F�[�h�A�E�g�������s����
	bool IsFadein;				//�t�F�[�h�C���������s����

public:

	//Effect(const char*, const char*, int, int, int, int, int, double, bool,Music*);	//�R���X�g���N�^	
	Effect(const char*, const char*, int, int, int, int, int, double, bool);	//�R���X�g���N�^	
	~Effect();					//�f�X�g���N�^

	int GetWidth();			//�����擾
	int GetHeight();			//�������擾

	bool GetIsLoad(void);		//�ǂݍ��߂��H

	bool GetIsAnimeStop();	//�A�j���[�V�����̓X�g�b�v���������擾

	bool GetIsDrawEnd();		//�`��I���������擾

	void SetIsDrawEnd(bool);	//�`��I���������ݒ�

	void ResetIsAnime();		//�A�j���[�V�������X�g�b�v�����������Z�b�g

	void Draw(int, int);	//�`��
	void DrawCenter();		//��ʒ����ɕ`��

	void SetInit();						//�����ݒ�

	void SetIsFadeout(bool);			//�t�F�[�h�A�E�g�����邩�ݒ�
	void SetIsFadein(bool);				//�t�F�[�h�C�������邩�ݒ�

	bool FadeOut(int, int, int, int);		//�t�F�[�h�A�E�g�G�t�F�N�g
	bool FadeIn(int, int, int, int);	//�t�F�[�h�C���G�t�F�N�g

	void SetIsDraw(bool);			//�`�悵�Ă悢���ݒ�
	bool GetIsDraw();				//�`�悵�Ă悢���擾

};
