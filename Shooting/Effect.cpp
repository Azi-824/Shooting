//Effect.cpp
//�G�t�F�N�g�N���X

//################## �w�b�_�t�@�C���ǂݍ��� ##################
#include "Effect.hpp"

//################## �N���X��` #######################

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
//Effect::Effect(const char* dir, const char* name, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed, bool IsLoop,Music* se)
//{
//	//�����o�[�ϐ�������
//	IsLoad = false;			//�ǂݍ��߂����H
//	IsDrawEnd = false;		//�`��I��������?
//	IsFadein = false;		//�t�F�[�h�C���������s��Ȃ�
//	IsFadeout = false;		//�t�F�[�h�A�E�g�������s��Ȃ�
//	IsCreateSe = false;		//���ʉ��̃I�u�W�F�N�g���쐬���Ă��Ȃ�
//	Width = 0;				//������������
//	Height = 0;				//������������
//
//	//�摜��ǂݍ���
//	std::string LoadfilePath;		//�摜�̃t�@�C���p�X���쐬
//	LoadfilePath += dir;
//	LoadfilePath += name;
//
//	vector<int> work(SplitNumALL);	//�����ǂݍ��݂œ����n���h�����i�[����z��𑍕������ŏ�����
//
//	//�摜�𕪊����ēǂݍ���
//	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SplitNumY, SplitWidth, SplitHeight, &work.front());
//	Handle = work;
//
//	if (Handle.front() == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
//	{
//		std::string ErrorMsg(EFFECT_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
//		ErrorMsg += TEXT('\n');						//���s
//		ErrorMsg += LoadfilePath;					//�摜�̃p�X
//
//		MessageBox(
//			NULL,
//			ErrorMsg.c_str(),	//char * ��Ԃ�
//			TEXT(EFFECT_ERROR_TTILE),
//			MB_OK);
//
//		return;
//	}
//
//	ChangeMaxCnt = (GAME_FPS_SPEED * changeSpeed);
//	ChangeCnt = 0;	//�A�j���[�V��������t���[���̃J�E���g
//
//	NextChangeSpeed = changeSpeed;	//�摜��ς��鑬��
//
//	IsAnimeLoop = IsLoop;		//�A�j���[�V���������[�v���邩
//	IsAnimeStop = false;		//�A�j���[�V�����𓮂���
//	IsDraw = false;				//�`�悵�Ă悢���i�ŏ��͕`�悵�Ȃ��j
//
//	Handle_itr = Handle.begin();	//�擪�v�f���C�e���[�^�ɐݒ�
//
//	Se = se;			//���ʉ��ǉ�
//
//	IsLoad = true;		//�ǂݍ��߂�
//
//	//vector�̃�����������s��
//	vector<int> v;			//���vector���쐬����
//	work.swap(v);			//��ƒ��g�����ւ���
//
//	return;
//
//}

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
Effect::Effect(const char* dir, const char* name, int SplitNumALL, int SpritNumX, int SplitNumY, int SplitWidth, int SplitHeight, double changeSpeed, bool IsLoop)
{
	//�����o�[�ϐ�������
	IsLoad = false;			//�ǂݍ��߂����H
	IsDrawEnd = false;		//�`��I��������?
	IsFadein = false;		//�t�F�[�h�C���������s��Ȃ�
	IsFadeout = false;		//�t�F�[�h�A�E�g�������s��Ȃ�
	IsCreateSe = false;		//���ʉ��̃I�u�W�F�N�g���쐬���Ă��Ȃ�
	Width = 0;				//������������
	Height = 0;				//������������

	//�摜��ǂݍ���
	string LoadfilePath;		//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	vector<int> work(SplitNumALL);	//�����ǂݍ��݂œ����n���h�����i�[����z��𑍕������ŏ�����

	//�摜�𕪊����ēǂݍ���
	LoadDivGraph(LoadfilePath.c_str(), SplitNumALL, SpritNumX, SplitNumY, SplitWidth, SplitHeight, &work.front());
	Handle = work;

	if (Handle.front() == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErrorMsg(EFFECT_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErrorMsg += TEXT('\n');						//���s
		ErrorMsg += LoadfilePath;					//�摜�̃p�X

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * ��Ԃ�
			TEXT(EFFECT_ERROR_TTILE),
			MB_OK);

		return;
	}

	ChangeMaxCnt = (GAME_FPS_SPEED * changeSpeed);
	ChangeCnt = 0;	//�A�j���[�V��������t���[���̃J�E���g

	NextChangeSpeed = changeSpeed;	//�摜��ς��鑬��

	IsAnimeLoop = IsLoop;		//�A�j���[�V���������[�v���邩
	IsAnimeStop = false;		//�A�j���[�V�����𓮂���
	IsDraw = false;				//�`�悵�Ă悢���i�ŏ��͕`�悵�Ȃ��j

	Handle_itr = Handle.begin();	//�擪�v�f���C�e���[�^�ɐݒ�

	IsLoad = true;		//�ǂݍ��߂�

	//vector�̃�����������s��
	vector<int> v;			//���vector���쐬����
	work.swap(v);			//��ƒ��g�����ւ���

	return;

}


//�f�X�g���N�^
Effect::~Effect()
{

	DeleteGraph(Handle.front());

	//delete Se;	//Se�j��

	//vector�̃�����������s��
	vector<int> v;			//���vector���쐬����
	Handle.swap(v);			//��ƒ��g�����ւ���

}

//�����擾
int Effect::GetWidth()
{
	return Width;
}

//�������擾
int Effect::GetHeight()
{
	return Height;
}

//�ǂݍ��߂��H
bool Effect::GetIsLoad(void)
{
	return IsLoad;
}

//�A�j���[�V�����̓X�g�b�v���������擾
bool  Effect::GetIsAnimeStop()
{
	return IsAnimeStop;
}

//�`��I���������ǂ����擾
bool Effect::GetIsDrawEnd()
{
	return IsDrawEnd;
}

//�`��I���������ݒ�
void Effect::SetIsDrawEnd(bool isend)
{
	IsDrawEnd = isend;
	return;
}

//�A�j���[�V�������X�g�b�v�����������Z�b�g
void Effect::ResetIsAnime()
{
	IsAnimeStop = false;
	IsDrawEnd = false;
	return;
}

//�`��
/*
�����Fint�FX�̕`��ʒu
�����Fint�FY�̕`��ʒu
*/
void Effect::Draw(int x, int y)
{

	if (IsDraw)		//�`�悵�Ă悯���
	{
		if (IsAnimeStop == false)	//�A�j���[�V�������X�g�b�v�����Ȃ��Ȃ�
		{
			DrawGraph(x, y, *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
			//Se->PlayOne(false);	//���ʉ��Đ�
		}
		else
		{
			//Se->PlayReset();	//�Đ���ԃ��Z�b�g
			IsDrawEnd = true;	//�`��I��
		}

		if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
		{
			//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
			if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
			{
				//�A�j���[�V���������[�v���Ȃ��Ȃ�
				if (IsAnimeLoop == false)
				{
					IsAnimeStop = true;	//�A�j���[�V�������~�߂�
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

}

//��ʒ����ɕ`��
void Effect::DrawCenter()
{

	if (IsDraw)	//�`�悵�Ă悯���
	{
		if (IsAnimeStop == false)	//�A�j���[�V�������X�g�b�v�����Ȃ��Ȃ�
		{
			DrawGraph((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
			//Se->PlayOne(false);				//���ʉ��Đ�
		}
		else
		{
			//Se->PlayReset();	//�Đ���ԃ��Z�b�g
			IsDrawEnd = true;		//�`��I��
		}

		if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
		{
			//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
			if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
			{
				//�A�j���[�V���������[�v���Ȃ��Ȃ�
				if (IsAnimeLoop == false)
				{
					IsAnimeStop = true;	//�A�j���[�V�������~�߂�
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

}

//�����ݒ�
void Effect::SetInit(void)
{
	GetGraphSize(Handle.front(), &Width, &Height);		//�T�C�Y�擾
	//Se->SetInit(DX_PLAYTYPE_BACK, 30);					//�����ݒ�
}

//�t�F�[�h�A�E�g�����邩�ݒ�
void Effect::SetIsFadeout(bool isfadeout)
{
	IsFadeout = isfadeout;
	return;
}

//�t�F�[�h�C�������邩�ݒ�
void Effect::SetIsFadein(bool isfadein)
{
	IsFadein = isfadein;
	return;
}

//�t�F�[�h�A�E�g�G�t�F�N�g
//�����Fint�F���߂��������͈͂�X�ʒu
//�����Fint�F���߂��������͈͂�Y�ʒu
//�����Fint�F���߂��������͈͂̉���
//�����Fint�F���߂��������͈͂̍���
//�߂�l�Fbool�F�t�F�[�h�A�E�g���I��������
//true�F�I���Ffalse�F�I�����Ă��Ȃ�
bool Effect::FadeOut(int x, int y, int width, int height)
{

	static int cnt = 0;				//�J�E���g�p
	static bool end_flg = false;	//�t�F�[�h�I���t���O

	if (IsFadeout)		//�t�F�[�h�A�E�g����Ƃ�
	{

		if (!end_flg)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{
			//60�t���[�����A�҂�
			if (cnt < FADE_MAX_CNT)
			{
				++cnt;	//�J�E���g�A�b�v
			}
			else
			{
				end_flg = true;	//�t�F�[�h�I��
			}

			//�t�F�[�h�A�E�g�̏���
			double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
			DrawBox(x, y, width, height, COLOR_BLACK, TRUE);						//�^���Âȉ�ʂɂ���
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�

		}
		else if (end_flg)	//�t�F�[�h�A�E�g�I��������
		{
			IsFadeout = false;	//�t�F�[�h�A�E�g���Ȃ�
			cnt = 0;			//�J�E���g���Z�b�g
			end_flg = false;	//�I���t���O���Z�b�g
		}

	}
	else		//�t�F�[�h�A�E�g�����Ȃ���
	{
		cnt = 0;			//�J�E���g���Z�b�g
		end_flg = false;	//�I���t���O���Z�b�g
		return true;		//�t�F�[�h�A�E�g�͏I����Ă���
	}

	return end_flg;

}

//�t�F�[�h�C���G�t�F�N�g
//�����Fint�F���߂��������͈͂�X�ʒu
//�����Fint�F���߂��������͈͂�Y�ʒu
//�����Fint�F���߂��������͈͂̉���
//�����Fint�F���߂��������͈͂̍���
//�߂�l�Fbool�F�t�F�[�h�C�����I��������
//true�F�I���Ffalse�F�I�����Ă��Ȃ�
bool Effect::FadeIn(int x, int y, int width, int height)
{
	static int cnt = FADE_MAX_CNT;	//�J�E���g�p
	static bool end_flg = false;	//�t�F�[�h�I���t���O

	if (IsFadein)		//�t�F�[�h�C������Ƃ�
	{

		if (!end_flg)	//�t�F�[�h�C���I�����Ă��Ȃ����
		{
			//60�t���[�����A�҂�
			if (cnt > 0)
			{
				--cnt;	//�J�E���g�_�E��
			}
			else
			{
				end_flg = true;	//�t�F�[�h�I��
			}

			//�t�F�[�h�C���̏���
			double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
			DrawBox(x, y, width, height, COLOR_BLACK, TRUE);						//�^���Âȉ�ʂɂ���
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�

		}
		else if (end_flg)	//�t�F�[�h�C���I��������
		{
			cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g
			end_flg = false;		//�G���h�t���O���Z�b�g
			IsFadein = false;	//�t�F�[�h�C�����Ȃ�
		}

	}
	else		//�t�F�[�h�C�������Ȃ���
	{
		cnt = FADE_MAX_CNT;	//�J�E���g���Z�b�g
		end_flg = false;	//�I���t���O���Z�b�g
		return true;		//�t�F�[�h�C���͏I����Ă���
	}

	return end_flg;

}

//�`�悵�Ă悢���ݒ�
//�����Fbool�F�`�悵�Ă悢��
//�����Fint�F�`�悷��G�t�F�N�g�̎��
void Effect::SetIsDraw(bool isdraw)
{
	IsDraw = isdraw;
}

//�`�悵�Ă悢���擾
//�����Fint�F�`�悷��G�t�F�N�g�̎��
bool Effect::GetIsDraw()
{
	return IsDraw;
}
