//Animation.cpp
//�A�j���[�V�������Ǘ�����N���X

//################ �w�b�_�t�@�C���ǂݍ��� ##################
#include "Animation.hpp"

//################ �N���X��` ##############

//�R���X�g���N�^
/*
���@���Fconst char *�F�摜�̃f�B���N�g��
���@���Fconst char *�F�摜�̖��O
���@���Fint�F�摜�̑�������
���@���Fint�F�摜�̉������̕�����
���@���Fint�F�摜�̏c�����̕�����
���@���Fint�F�摜�̕������ꂽ���̑傫��
���@���Fint�F�摜�̕������ꂽ�c�̑傫��
���@���Fdouble�F���̉摜�ɕύX���鑬��
���@���Fbool�F�A�j���[�V���������[�v���邩�ǂ���
*/
Animation::Animation(const char* dir, const char* name, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed, bool IsLoop)
{
	//�����o�[�ϐ�������
	IsLoad = false;			//�ǂݍ��߂����H
	IsDrawEnd = false;		//�`��I��������?
	Width = 0;				//������������
	Height = 0;				//������������

	//�摜��ǂݍ���
	string LoadfilePath;		//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	vector<int> work(SplitNumALL);	//�����ǂݍ��݂œ����n���h�����i�[����z��𑍕������ŏ�����
	/*
	��ŏC��������
	Handle.resize(SplitNumAll)
	*/

	//�摜�𕪊����ēǂݍ���
	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SplitNumY, SplitWidth, SplitHeight, &work.front());
	Handle = work;

	if (Handle.front() == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErrorMsg(ANIMATION_ERROR_MSG);		//�G���[���b�Z�[�W�쐬
		ErrorMsg += TEXT('\n');						//���s
		ErrorMsg += LoadfilePath;					//�摜�̃p�X

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * ��Ԃ�
			TEXT(ANIMATION_ERROR_TTILE),
			MB_OK);

		return;
	}

	ChangeMaxCnt = (GAME_FPS_SPEED * changeSpeed);
	ChangeCnt = 0;	//�A�j���[�V��������t���[���̃J�E���g

	NextChangeSpeed = changeSpeed;	//�摜��ς��鑬��

	IsAnimeLoop = IsLoop;		//�A�j���[�V���������[�v���邩

	Handle_itr = Handle.begin();	//�擪�v�f���C�e���[�^�ɐݒ�

	IsLoad = true;		//�ǂݍ��߂�

	//vector�̃�����������s��
	vector<int> v;			//���vector���쐬����
	work.swap(v);			//��ƒ��g�����ւ���

	return;

}

//�f�X�g���N�^
Animation::~Animation()
{
	DeleteGraph(Handle.front());

	//vector�̃�����������s��
	vector<int> v;			//���vector���쐬����
	Handle.swap(v);			//��ƒ��g�����ւ���

}

//�����擾
int Animation::GetWidth()
{
	return Width;
}

//�������擾
int Animation::GetHeight()
{
	return Height;
}

//�ǂݍ��߂��H
bool Animation::GetIsLoad(void)
{
	return IsLoad;
}

//�`��I���������ǂ����擾
bool Animation::GetIsDrawEnd()
{
	return IsDrawEnd;
}

//���Z�b�g
void Animation::Reset()
{
	IsDrawEnd = false;
}

//�`��
/*
�����Fint�FX�̕`��ʒu
�����Fint�FY�̕`��ʒu
*/
void Animation::Draw(int x, int y)
{
	if (IsDrawEnd == false)	//�A�j���[�V�������I����Ă��Ȃ����
	{
		DrawGraph(x, y, *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
	}

	if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
	{
		//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
		if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
		{
			//�A�j���[�V���������[�v���Ȃ��Ȃ�
			if (IsAnimeLoop == false)
			{
				IsDrawEnd = true;	//�`��I��
			}

			//����̕`��ɔ����āA�擪�̉摜�ɖ߂��Ă���
			Handle_itr = Handle.begin();	//�C�e���[�^(�|�C���^)��v�f�̍ŏ��ɖ߂�
		}
		else
		{
			++Handle_itr;	//���̃C�e���[�^(�|�C���^)(���̉摜)�Ɉړ�����
		}

		ChangeCnt = 0;	//�J�E���g������
	}
	else
	{
		++ChangeCnt;	//�J�E���g�A�b�v
	}

}

//��ʒ����ɕ`��
void Animation::DrawCenter()
{
	if (IsDrawEnd == false)	//�A�j���[�V�������I����Ă��Ȃ����
	{
		DrawGraph((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
	}

	if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
	{
		//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
		if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
		{
			//�A�j���[�V���������[�v���Ȃ��Ȃ�
			if (IsAnimeLoop == false)
			{
				IsDrawEnd = true;	//�`��I��
			}

			//����̕`��ɔ����āA�擪�̉摜�ɖ߂��Ă���
			Handle_itr = Handle.begin();	//�C�e���[�^(�|�C���^)��v�f�̍ŏ��ɖ߂�
		}
		else
		{
			++Handle_itr;	//���̃C�e���[�^(�|�C���^)(���̉摜)�Ɉړ�����
		}

		ChangeCnt = 0;	//�J�E���g������
	}
	else
	{
		++ChangeCnt;	//�J�E���g�A�b�v
	}

}
