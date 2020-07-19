/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* KeyDown.cpp     																				   */
/* KeyDown�N���X																				   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "KeyDown.hpp"

//########## �N���X�̒�` ##########

//�C���X�^���X�𐶐�
char KeyDown::AllKeyState[256];

//�L�[�̓��͏�Ԃ��X�V����
VOID KeyDown::KeyDownUpdate(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL KeyDown::IsKeyDown(int keycode)
{
	if (this->AllKeyState[keycode] != 0)
		return TRUE;
	else
		return FALSE;
}

//�L�[���������u�Ԃ���true��Ԃ�
bool KeyDown::IsKeyDownOne(int keycode)
{
	if (this->AllKeyState[keycode] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�L�[���͂����邩�擾
bool KeyDown::IsKeyInput()
{
	if (CheckHitKeyAll(DX_CHECKINPUT_KEY) == 0)	//�L�[���͂������
	{
		return true;
	}
	else	//�Ȃ����
	{
		return false;
	}
}

//���͒��̃L�[�R�[�h���擾
//�߂�l�Fint�F���͒��̃L�[�R�[�h�A
//���͒��̃L�[�R�[�h���Ȃ��ꍇ�A�|1��Ԃ�
int KeyDown::GetInputKeyCode()
{

	for (int i = 0; i < 256; i++)
	{
		if (this->AllKeyState[i] == 1)
		{
			return i;
		}
	}

	return -1;

}

//�R���X�g���N�^
KeyDown::KeyDown()
{
}

//�f�X�g���N�^
KeyDown::~KeyDown()
{
}


//########## �O���I�u�W�F�N�g ##########
extern KeyDown *keydown;