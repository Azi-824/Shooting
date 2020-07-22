//Target.hpp
//�I�̊�ɂȂ�N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"
#include "Image.hpp"

//############### �}�N����` ####################

//############### �N���X��` ####################
class Target
{
protected:

	Image* img;		//�摜
	RECT rect;		//�̈�

public:

	Target();		//�R���X�g���N�^
	~Target();		//�f�X�g���N�^

	virtual void Event() = 0;	//�I���N���b�N�����Ƃ��̃C�x���g(�ォ��X�R�A�N���X���󂯎��AEvent()���ŃX�R�A���Z������悤�ɕύX)
	RECT GetRect();				//�̈�̎擾

	/*
	�}�E�X�N���X�ɒǉ�
	bool OnClick(RECT);	//�n���ꂽ�̈�����N���b�N����������
	*/
};
