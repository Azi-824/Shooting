//Effect.cpp
//�G�t�F�N�g�N���X

//################## �w�b�_�t�@�C���ǂݍ��� ##################
#include "Effect.hpp"

//################## �N���X��` #######################

//�R���X�g���N�^
//����:Animation* :�A�j���[�V����
//����:Music* :���ʉ�
Effect::Effect(Animation* anim,Music* se)
{
	//�����o�[������
	IsFadein = false;	//�t�F�[�h�C�����邩
	IsFadeout = false;	//�t�F�[�h�A�E�g���邩

	this->anim = anim;	//�A�j���[�V����
	this->se = se;		//���ʉ�
}

//�R���X�g���N�^
Effect::Effect()
{
	//�����o�[������
	IsFadein = false;	//�t�F�[�h�C�����邩
	IsFadeout = false;	//�t�F�[�h�A�E�g���邩
}

//�f�X�g���N�^
Effect::~Effect()
{

	delete anim;	//anim�j��
	delete se;		//se�j��

}

//�G�t�F�N�g��ݒ�
//����:Animation* :�A�j���[�V����
//����:Music* :���ʉ�
void Effect::SetEffect(Animation* anim,Music* se)
{
	this->anim = anim;
	this->se = se;
}

//�`��
/*
�����Fint�FX�̕`��ʒu
�����Fint�FY�̕`��ʒu
*/
void Effect::Draw(int x, int y)
{
	anim->Draw(x, y);	//�A�j���[�V�����`��
	se->PlayOne(false);	//���ʉ��Đ�
}

//��ʒ����ɕ`��
void Effect::DrawCenter()
{
	anim->DrawCenter();	//�A�j���[�V�����`��
	se->PlayOne(false);	//���ʉ��Đ�
}

//�w�肳�ꂽ�̈���̒����ɕ`��
void Effect::DrawCenter(RECT rect)
{
	anim->DrawCenter(rect);	//�A�j���[�V�����`��
	se->PlayOne(false);	//���ʉ��Đ�
}

//�����ݒ�
void Effect::SetInit(void)
{
	anim->SetInit();	//�A�j���[�V���������ݒ�
	se->SetInit(DX_PLAYTYPE_BACK, 30);		//�����ݒ�
}

//�G�t�F�N�g�I���������擾
bool Effect::GetIsEffectEnd()
{
	return anim->GetIsDrawEnd();
}

//���Z�b�g
void Effect::Reset()
{
	anim->Reset();	//�A�j���[�V�������Z�b�g
	se->Reset();//���ʉ����Z�b�g
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
