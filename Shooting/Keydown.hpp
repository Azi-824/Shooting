/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* KeyDown.cpp     																				   */
/* KeyDown�N���X																				   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Global.hpp"

//########## �N���X�̒�` ##########

class KeyDown
{
private:
	static char AllKeyState[256];		//���ׂẴL�[�̏�Ԃ�����	//static�́A���ʂ̕ϐ����g�p����

public:
	static VOID KeyDownUpdate(VOID);	//�L�[�̓��͏�Ԃ��X�V����	//static�́A���ʂ̊֐����g�p����

	//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
	//���@���F�L�[�R�[�h
	BOOL IsKeyDown(int);

	bool IsKeyDownOne(int);	//�L�[���������u�Ԃ���true��Ԃ�
	bool IsKeyInput();		//�L�[���͂����邩�擾
	int GetInputKeyCode();	//���͒��̃L�[�R�[�h���擾

public:
	KeyDown();			//�R���X�g���N�^
	virtual ~KeyDown();	//�f�X�g���N�^
};


