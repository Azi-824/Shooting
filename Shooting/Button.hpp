//Button.hpp
//�{�^���̃N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Global.hpp"
#include "Image.hpp"

//################# �}�N����` ################
#define BT_IMG_DIR			R"(.\Image\Button)"	//�{�^���̉摜�̃f�B���N�g��

#define BT_START_IMG_NAME	R"(\start.png)"		//�{�^���̉摜(start)
#define BT_END_IMG_NAME		R"(\end.png)"		//�{�^���̉摜(end)

#define BT_START_X	150		//�X�^�[�g�{�^��X�ʒu
#define BT_START_Y	500		//�X�^�[�g�{�^��Y�ʒu
#define BT_END_X	500		//�X�^�[�g�{�^��X�ʒu
#define BT_END_Y	500		//�X�^�[�g�{�^��Y�ʒu

//################# �񋓌^ #################
enum BT_TYPE
{
	BT_START,		//�X�^�[�g
	BT_END			//�G���h
};

//################# �N���X��` ################
class Button
{
private:

	Image* img;	//�摜
	RECT rect;	//�̈�

	int Element;			//�v�f�ԍ�
	static int ElementCnt;	//�v�f��

public:

	Button(Image*);	//�R���X�g���N�^
	~Button();		//�f�X�g���N�^

	void SetInit(int,int);	//�����ݒ�

	bool OnClick();	//�N���b�N���ꂽ��
	void Draw();	//�`��
	int GetElement();	//�v�f�ԍ��擾
	
	template <typename F>
	void Event(F func)	//�N���b�N���ꂽ���̃C�x���g
	{
		func();
	}

};
