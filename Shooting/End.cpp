//End.cpp
//�G���h��ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "End.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
End::End()
{
	
}

//�f�X�g���N�^
End::~End()
{

}

//�f�[�^�Ǎ�
bool End::DataLoad()
{
	return true;
}

//�����ݒ�
void End::SetInit()
{
	//back->SetInit();	//�w�i�摜�����ݒ�
}


//�G���h��ʂ̏���
void End::PlayScene()
{
	//************************** �����n *********************************
	static bool IsInit = false;	//�����ݒ��������
	if (!IsInit)	//�����ݒ�����Ă��Ȃ�������
	{
		SetInit();	//�����ݒ�
		IsInit = true;	//�����ݒ芮��
	}

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
	}


	//**************************** �`��n *******************************
	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, GetColor(255, 255, 255));	//�e�X�g�p�̃e�L�X�g��`��

}