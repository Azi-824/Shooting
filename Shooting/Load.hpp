//Load.hpp
//�ǂݍ��݉�ʂ̃N���X�iScene�N���X����h���j

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� #################
#include "Scene.hpp"

//################### �}�N����` ###################
#define TEXT_DISCRIPTION	"��ʂɕ\�������I���N���b�N���悤�I\n���e���N���b�N����ƁA\n���Ԃ������Ă��܂�����C��t���悤�I"

//################### �N���X��` ###################
class Load : public Scene	//Scene�N���X���p��
{
private:

	bool IsGameStart;	//�Q�[���X�^�[�g�ł��邩

public:

	Load();	//�R���X�g���N�^ 
	~Load();				//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void Run() override;	//���[�h��ʂ̏���

};
