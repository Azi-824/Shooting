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

private:

	int DrawX;		//�`��X�ʒu
	int DrawY;		//�`��Y�ʒu

	void CreateDrawPos();	//�`��ʒu�𐶐�

protected:

	Image* img;		//�摜
	RECT rect;		//�̈�
	int Score;		//�X�R�A

public:

	Target();		//�R���X�g���N�^
	~Target();		//�f�X�g���N�^

	virtual void SetInit(int);	//�����ݒ�
	virtual void Event() = 0;	//�I���N���b�N�����Ƃ��̃C�x���g(�ォ��X�R�A�N���X���󂯎��AEvent()���ŃX�R�A���Z������悤�ɕύX)
	RECT GetRect();				//�̈�̎擾
	void Draw();				//�`��

};
