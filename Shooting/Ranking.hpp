//Ranking.hpp
//�����L���O��ʂ̏���

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"

//############# �}�N����` ##############

//############# �N���X��` ##############
class Ranking : public Scene	//Scene���p��
{
private:

public:

	Ranking();			//�R���X�g���N�^
	~Ranking();					//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void Run() override;	//�G���h��ʂ̏���

};
