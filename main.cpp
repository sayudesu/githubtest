#include "DxLib.h"

#include "game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	//�E�B���h�E���ݒ�
	SetMainWindowText(Game::kTitelText);
	//��ʃT�C�Y�ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	while(ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();

		//��ʂ��N���A����
		ClearDrawScreen();
		//�t�H���g�ύX
		ChangeFont("�l�r ����");
		//�t�H���g�T�C�Y��ύX
		SetFontSize(64);
		//������\��
		DrawString(Game::kScreenWidth /2, Game::kScreenHeight /2,"github test",GetColor(255,255,255));

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		//esc�������ďI��
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		//60fps�Œ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}