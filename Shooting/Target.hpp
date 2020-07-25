//Target.hpp
//�I�̊�ɂȂ�N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"
#include "Image.hpp"
#include "Score.hpp"
#include "Time.hpp"
#include "Effect.hpp"

//############### �}�N����` ####################
#define LIMIT_MIN	3	//�������Ԃ̍ŏ��l
#define LIMIT_MAX	8	//�������Ԃ̍ő�l

//############### �񋓌^ ####################
enum TARGET_NAME
{
	TG_NAME_TOY01,	//��������01
	TG_NAME_TOY02,	//��������02
	TG_NAME_TOY03,	//��������03
	TG_NAME_BOMB01,	//���e1
	TG_NAME_BOMB02,	//���e2
	TG_NAME_BOMB03,	//���e3
	TG_NAME_ITEM01,	//�A�C�e��1
	TG_NAME_ITEM02	//�A�C�e��2
};

//############### �N���X��` ####################
class Target
{

private:

	int DrawX;		//�`��X�ʒu
	int DrawY;		//�`��Y�ʒu
	bool EventFlg;	//�C�x���g�t���O

protected:

	Image* img;		//�摜
	RECT rect;		//�̈�
	Time* time;		//����
	Effect* effect;	//�G�t�F�N�g
	int Element;	//�v�f�ԍ�
	static vector<RECT> use_rect;	//���Ɏg�p����Ă���̈�
	static vector<int> ScoreTable;	//�X�R�A�e�[�u��

	void CreateDrawPos();		//�`��ʒu�𐶐�
	bool RectOverRap();	//�����̗̈悪�A�g�p�ς݂��ǂ������ׂ�

public:

	Target();		//�R���X�g���N�^
	~Target();		//�f�X�g���N�^

	virtual void UpDate();		//����s������
	virtual void SetInit();		//�����ݒ�
	virtual void Event(Time*) = 0;	//�I���N���b�N�����Ƃ��̃C�x���g
	bool OnClick();				//�N���b�N������
	void Draw();				//�`��
	bool GetEventFlg();			//�C�x���g�t���O�擾
	void SetEventFlg(bool);		//�C�x���g�t���O�ݒ�

};
