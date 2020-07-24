//Music.cpp
//���y�p�N���X

//################### �w�b�_�t�@�C���ǂݍ��� ####################
#include "Music.hpp"

//################## �N���X��` ###########################

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
//���@���Fint�F���f�ނ̎�ސ�
Music::Music(const char *dir, const char *name)
{
	//�����o�ϐ���������
	FilePath = "";	//�p�X
	FileName = "";	//���O

	IsLoad = false;	//�ǂݍ��߂����H

	//����ǂݍ���
	string LoadfilePath;	//���̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	Handle = LoadSoundMem(LoadfilePath.c_str());	//���̓ǂݍ���

	if (Handle == -1)	//�����ǂݍ��߂Ȃ������Ƃ�
	{
		string ErroeMsg(MUSIC_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');					//���s
		ErroeMsg += LoadfilePath;				//���̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(MUSIC_ERROR_TITLE),
			MB_OK);

		return;
	}

	FilePath = LoadfilePath;		//���̃p�X��ݒ�
	FileName = name;				//���̖��O��ݒ�

	PlayType = DX_PLAYTYPE_BACK;	//�ŏ��͍Đ����@���o�b�N�O���E���h�Đ��ɂ���

	IsLoad = true;				//�ǂݍ��ݐ���

	IsPlayed = false;		//�Đ��ς݂ł͂Ȃ�

	return;

}

//�f�X�g���N�^
Music::~Music()
{
	DeleteMusicMem(Handle);		//���̃n���h���̍폜
}

//�ǂݍ��߂����ǂ������擾
bool Music::GetIsLoad()
{
	return IsLoad;
}

//�����Đ�����Ă��邩�擾
//�߂�l�F�Đ����Ftrue�@�Đ�������Ȃ��Ffalse
bool Music::GetIsPlay()
{
	return CheckSoundMem(Handle);
}


//�����ݒ�
void Music::SetInit(int type, double volume)
{
	PlayType = type;	//�Đ����@�ݒ�
	ChengeVolume(volume);
}

//�Đ����@��ύX����
void Music::ChengePlayType(int type)
{
	PlayType = type;	
	return;
}

//���ʂ�ύX����
//�����Fint�F����(0�`100%�Ŏw��)
void Music::ChengeVolume(double volume)
{
	ChangeVolumeSoundMem(VOLUME_MAX * (volume / 100), Handle);
	return;
}

//�����Đ�����
void Music::Play(bool check)
{
	if (check)	//�v���C�����m�F����ꍇ
	{
		if (!GetIsPlay())		//�v���C������Ȃ����
		{
			PlaySoundMem(Handle, PlayType);	//���̍Đ�
		}
	}
	else		//�m�F���Ȃ��ꍇ
	{
		PlaySoundMem(Handle, PlayType);	//���̍Đ�
	}

	return;
}

//�����Đ�����(1�񂾂�)
void Music::PlayOne(bool check)
{
	if (!IsPlayed)		//�Đ��ς݂���Ȃ����
	{
		if (check)	//�v���C�����m�F����ꍇ
		{
			if (!GetIsPlay())		//�v���C������Ȃ����
			{
				PlaySoundMem(Handle, PlayType);	//���̍Đ�

				IsPlayed = true;		//�Đ��ς�

			}

		}
		else		//�m�F���Ȃ��ꍇ
		{
			PlaySoundMem(Handle, PlayType);	//���̍Đ�

			IsPlayed = true;		//�Đ��ς�
		}
	}
}


//�Đ��ς݂��ǂ��������Z�b�g����
void Music::PlayReset()
{
	IsPlayed = false;	//�Đ��ς݂���Ȃ�
	return;
}

//�����~�߂�
void Music::Stop(void)
{
	StopSoundMem(Handle);		//�����~�߂�

}