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
	TGNAME_GHOST,	//������
	TGNAME_BOMB1	//���e1
};

//############### �N���X��` ####################
class Target
{

private:

	int DrawX;		//�`��X�ʒu
	int DrawY;		//�`��Y�ʒu
	bool EventFlg;	//�C�x���g�t���O

	void CreateDrawPos();	//�`��ʒu�𐶐�

protected:

	Image* img;		//�摜
	RECT rect;		//�̈�
	Time* time;		//����
	Effect* effect;	//�G�t�F�N�g
	int score;		//�X�R�A

	void CommonEvent();	//���ʂ̃C�x���g����

public:

	Target();		//�R���X�g���N�^
	~Target();		//�f�X�g���N�^

	virtual void UpDate() = 0;	//����s������
	virtual void SetInit(int);	//�����ݒ�
	virtual void Event() = 0;	//�I���N���b�N�����Ƃ��̃C�x���g
	bool OnClick();				//�N���b�N������
	RECT GetRect();				//�̈�̎擾
	void Draw();				//�`��
	bool GetEventFlg();			//�C�x���g�t���O�擾
	void SetEventFlg(bool);		//�C�x���g�t���O�ݒ�

};
