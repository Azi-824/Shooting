//Target.hpp
//�I�̊�ɂȂ�N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"
#include "Image.hpp"
#include "Score.hpp"
#include "Time.hpp"

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

	void CreateDrawPos();	//�`��ʒu�𐶐�

protected:

	Image* img;		//�摜
	RECT rect;		//�̈�
	Time* time;		//����
	int score;		//�X�R�A

public:

	Target();		//�R���X�g���N�^
	~Target();		//�f�X�g���N�^

	virtual void UpDate() = 0;	//����s������
	virtual void SetInit(int);	//�����ݒ�
	virtual void Event() = 0;	//�I���N���b�N�����Ƃ��̃C�x���g
	RECT GetRect();				//�̈�̎擾
	void Draw();				//�`��

};
