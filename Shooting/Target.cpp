//Target.cpp
//�I�̊�ɂȂ�N���X

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Target.hpp"

//################# �N���X��` ####################

//�R���X�g���N�^
Target::Target(){}

//�f�X�g���N�^
Target::~Target()
{
	delete img;	//img�j��
}

//�̈�擾
RECT Target::GetRect()
{
	return rect;
}
