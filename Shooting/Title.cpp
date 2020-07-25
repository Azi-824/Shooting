//Title.cpp
//�^�C�g����ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ##################
#include "Title.hpp"

//############ �N���X��` ################

//�R���X�g���N�^
Title::Title()
{
	
}

//�f�X�g���N�^
Title::~Title()
{
	for (auto i : bt_img) { delete i; }	//bt_img�j��
	for (auto b : button) { delete b; }	//button�j��
}

//�f�[�^�Ǎ�
bool Title::DataLoad()
{
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_TITLE)) { return false; }	//�w�i�摜�ǂݍ���
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_TITLE)) { return false; }	//BGM�ǂݍ���

	//�{�^���̉摜
	bt_img.push_back(new Image(BT_IMG_DIR, BT_START_IMG_NAME));	//�{�^���i�X�^�[�g�j�ǉ�
	bt_img.push_back(new Image(BT_IMG_DIR, BT_END_IMG_NAME));	//�{�^���i�G���h�j�ǉ�
	for (auto i : bt_img)
	{
		if (!i->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	}

	//�{�^��
	button.push_back(new Button(bt_img.at(BT_START)));	//�{�^���i�X�^�[�g�j����
	button.push_back(new Button(bt_img.at(BT_END)));	//�{�^���i�G���h�j����

	return true;	//�ǂݍ��ݐ���
}

//�����ݒ�
void Title::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�

	button.at(BT_START)->SetInit(BT_START_X, BT_START_Y);	//�X�^�[�g�{�^���ݒ�
	button.at(BT_END)->SetInit(BT_END_X, BT_END_Y);			//�G���h�{�^���ݒ�
}


//�^�C�g����ʂ̏���
void Title::Run()
{

	bgm->Play();	//BGM�𗬂�

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	//�{�^������
	for (auto b : button)
	{
		b->UpDate();//�X�V
		b->Draw();	//�{�^���`��
		if (b->OnClick())	//�{�^�����N���b�N���ꂽ��
		{
			switch (b->GetElement())	//�v�f�ԍ�����
			{

			case BT_START: //start

				//�N���b�N���ꂽ���̃C�x���g�������쐬
				b->Event([this]
					{
						bgm->Stop();			//BGM���~�߂�
						NowScene = SCENE_PLAY;	//�v���C��ʂ�
					});

				break;	//start

			case BT_END:	//end

				//�N���b�N���ꂽ���̃C�x���g�������쐬
				b->Event([this]
					{
						GameEnd = true;			//�Q�[���I��
					});

				break;	//start

			default:
				break;
			}
		}
	}

}