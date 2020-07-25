//Button.cpp
//�{�^���̃N���X

//############### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Button.hpp"

//############### �N���X��` ###############

int Button::ElementCnt = 0;	//�v�f��

//�R���X�g���N�^
Button::Button(Image* img)
{
	this->img = img;
	rect = { 0 };	//�̈揉����
	Element = ElementCnt++;	//�v�f�ԍ��ݒ�
}

//�f�X�g���N�^
Button::~Button()
{
	delete img;	//img�j��
}

//�����ݒ�
void Button::SetInit(int x,int y)
{
	img->SetInit();	//�摜�����ݒ�
	//�̈�ݒ�
	rect.left = x;						//����X
	rect.top = y;						//����Y
	rect.right = x + img->GetWidth();	//�E��X
	rect.bottom = y + img->GetHeight();	//�E��Y
}

//�{�^�����N���b�N���ꂽ��
bool Button::OnClick()
{
	return Mouse::OnLeftClick(rect);
}

//�`��
void Button::Draw()
{
	img->Draw(rect.left, rect.top);
}

//�v�f�ԍ��擾
int Button::GetElement()
{
	return Element;
}
