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
	TG_NAME_GHOST,	//������
	TG_NAME_BOMB1,	//���e1
	TG_NAME_ITEM	//�A�C�e��
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
	int score;		//�X�R�A

	void CommonEvent();	//���ʂ̃C�x���g����
	void CreateDrawPos();	//�`��ʒu�𐶐�

public:

	Target();		//�R���X�g���N�^
	~Target();		//�f�X�g���N�^

	virtual void UpDate();		//����s������
	virtual void SetInit(int);	//�����ݒ�
	virtual void Event() = 0;	//�I���N���b�N�����Ƃ��̃C�x���g
	bool OnClick();				//�N���b�N������
	void Draw();				//�`��
	bool GetEventFlg();			//�C�x���g�t���O�擾
	void SetEventFlg(bool);		//�C�x���g�t���O�ݒ�

};
