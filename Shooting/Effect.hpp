//Effect.hpp
//�G�t�F�N�g���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
#include "Animation.hpp"
#include "Music.hpp"

//###################### �}�N����` #################################

//###################### �񋓌^ ##########################
enum EFFECT_NAME
{
	EF_NAME_SHOT,		//�e���G�t�F�N�g
	EF_NAME_EXPLOSION,	//�����G�t�F�N�g
	EF_NAME_ITEM		//�A�C�e���G�t�F�N�g
};

using std::vector;
using std::string;
//################### �N���X��` #########################
class Effect
{
private:

	Animation* anim;			//�A�j���[�V����
	Music* se;					//���ʉ�

	bool IsFadeout;				//�t�F�[�h�A�E�g�������s����
	bool IsFadein;				//�t�F�[�h�C���������s����

public:

	Effect(Animation*,Music*);	//�R���X�g���N�^
	Effect();					//�R���X�g���N�^
	~Effect();					//�f�X�g���N�^

	void SetEffect(Animation*,Music*);	//�G�t�F�N�g��ݒ�

	void Draw(int, int);	//�`��
	void DrawCenter();		//��ʒ����ɕ`��
	void DrawCenter(RECT);	//�w�肳�ꂽ�̈���̒����ɕ`��

	void SetInit();						//�����ݒ�

	bool GetIsEffectEnd();				//�G�t�F�N�g�I���������擾
	void Reset();						//���Z�b�g

	void SetIsFadeout(bool);			//�t�F�[�h�A�E�g�����邩�ݒ�
	void SetIsFadein(bool);				//�t�F�[�h�C�������邩�ݒ�

	bool FadeOut(int, int, int, int);	//�t�F�[�h�A�E�g�G�t�F�N�g
	bool FadeIn(int, int, int, int);	//�t�F�[�h�C���G�t�F�N�g

};
