//main.hpp

#pragma once


//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Fps.hpp"
#include "Scene.hpp"
#include "Load.hpp"
#include "Title.hpp"
#include "Play.hpp"
#include "End.hpp"


//########## �}�N����` ##########
#define GAME_COLOR	32		//��ʂ̃J���[�r�b�g
#define GAME_FPS_SPEED					   60

#define GAME_WINDOW_NAME	"�˓I"				//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

//############## �v���g�^�C�v�錾 #############
bool GameLoop();			//�Q�[���̃��[�v
void AddScene();			//�V�[���ǉ�
void Delete_Class();		//�N���X���폜���鏈��