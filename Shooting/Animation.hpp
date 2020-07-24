//Animation.hpp
//�A�j���[�V�������Ǘ�����N���X

#pragma once

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"

//###################### �}�N����`�F�t�@�C���p�X�A���O ######################
#define ANIMATION_DIR				R"(.\Animation)"				//�A�j���[�V�����̉摜�t�@�C���̏ꏊ

#define ANIMATION_NAME_EXPLOSION	R"(\explosion.png)"				//�����A�j���[�V�����̉摜�̖��O

//###################### �}�N����`�F�G���[���b�Z�[�W ########################
#define ANIMATION_ERROR_TTILE	"ANIMATION_ERROR"						//�G���[�^�C�g��
#define ANIMATION_ERROR_MSG		"�A�j���[�V�������ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//############ �}�N����` ##############
//********************** �T�C�Y ************************
#define ANIM_EXPLOSION_WIDTH		240	//������
#define ANIM_EXPLOSION_HEIGHT		240	//��������


//********************** ������ **************************
#define ANIM_EXPLOSION_YOKO_CNT		7	//��������
#define ANIM_EXPLOSION_TATE_CNT		1	//�c������

//************************ �������� **************************
#define ANIM_EXPLOSION_ALL_CNT	ANIM_EXPLOSION_YOKO_CNT * ANIM_EXPLOSION_TATE_CNT	//��������

//************************ �`�摬�x ***************************
#define ANIM_EXPLOSION_SPEED		0.08

using std::vector;
using std::string;

//############ �N���X��` ##############
class Animation
{
private:

	vector<int> Handle;					//�n���h��
	vector<int>::iterator Handle_itr;	//�n���h���̃C�e���[�^

	int Width;					//��
	int Height;					//����

	double NextChangeSpeed;		//�A�j���[�V������ύX���鑬��(�b)
	int ChangeCnt;				//�A�j���[�V��������t���[���̃J�E���g
	int ChangeMaxCnt;			//�A�j���[�V��������t���[���̍ő�l

	bool IsAnimeLoop;			//�A�j���[�V�����̓��[�v����H
	bool IsDrawEnd;				//�`��I��������

	bool IsLoad;				//�ǂݍ��߂����H

public:

	Animation(const char*, const char*, int, int, int, int, int, double, bool);		//�R���X�g���N�^
	~Animation();																	//�f�X�g���N�^

	int GetWidth();			//�����擾
	int GetHeight();		//�������擾

	bool GetIsLoad(void);	//�ǂݍ��߂��H
	bool GetIsDrawEnd();	//�`��I���������擾

	void Reset();			//���Z�b�g

	void Draw(int, int);	//�`��
	void DrawCenter();		//��ʒ����ɕ`��


};