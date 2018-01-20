// Novel Game Engine LINKS for C++
// Coding by S.H.(GAMELINKS)

#include "DxLib.h"
#include <vector>
#include <string>
#include <fstream>

// �����̃T�C�Y
const std::int32_t moji_size = 24;

int DrawPointX, DrawPointY;	// ������`��̈ʒu
int SP, CP;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

//�X�N���v�g�i�[�ϐ�
static std::vector<std::string> Script;

// ���s�֐�
int Kaigyou(void)
{
	int TempGraph;

	// �`��s�ʒu���������
	DrawPointY++;

	// �`�����ŏ��ɖ߂�
	DrawPointX = 0;

	// ������ʂ���͂ݏo��Ȃ��ʂ��X�N���[��������
	if (DrawPointY * moji_size + moji_size > 480)
	{
		// �e���|�����O���t�B�b�N�̍쐬
		TempGraph = MakeGraph(640, 480);

		// ��ʂ̓��e���ہX�R�s�[����
		GetDrawScreenGraph(0, 0, 640, 480, TempGraph);

		// ��s����ɓ\��t����
		DrawGraph(0, -moji_size, TempGraph, FALSE);

		// ��ԉ��̍s�̕��������Ŗ��߂�
		DrawBox(0, 480 - moji_size, 640, 480, 0, TRUE);

		// �`��s�ʒu���������
		DrawPointY--;

		// �O���t�B�b�N���폜����
		DeleteGraph(TempGraph);
	}

	// �I��
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int EndFlag;	// �I���t���O
	char OneMojiBuf[3];	// �P�������ꎞ�L���z��

	SetGraphMode(640, 480, 16);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	// �`��ʒu�̏����ʒu�Z�b�g
	DrawPointX = 0;
	DrawPointY = 0;

	// �Q�ƕ����ʒu���Z�b�g
	SP = 0;	// �P�s�ڂ�
	CP = 0;	// �O����

			// �t�H���g�̃T�C�Y�Z�b�g
	SetFontSize(moji_size);

	// �I���t���O��|��
	EndFlag = 0;

	// ���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		char  Moji;

		// �����̕`��
		Moji = Script[SP][CP];
		switch (Moji)
		{
		case '@':	// ���s����

					// ���s��������юQ�ƕ����ʒu����i�߂�
			Kaigyou();
			CP++;

			break;

		case 'B':	// �{�^�������҂�����

					// �{�^�������҂�����юQ�ƕ����ʒu����i�߂�
			WaitKey();
			CP++;

			break;

		case 'E':	// �I������

					// �I���t���O�𗧂Ă邨��юQ�ƕ����ʒu����i�߂�
			EndFlag = 1;
			CP++;

			break;

		case 'C':	// �N���A����

					// ��ʂ����������ĕ`�敶���ʒu�������ʒu�ɖ߂�����юQ�ƕ����ʒu����i�߂�
			ClearDrawScreen();
			DrawPointY = 0;
			DrawPointX = 0;
			CP++;

			break;

		default:	// ���̑��̕���

					// �P�����������o��
			OneMojiBuf[0] = Script[SP][CP];
			OneMojiBuf[1] = Script[SP][CP + 1];
			OneMojiBuf[2] = '\0';

			// �P�����`��
			DrawString(DrawPointX * moji_size, DrawPointY * moji_size,
				OneMojiBuf, GetColor(255, 255, 255));

			// �Q�ƕ����ʒu���Q�o�C�g���߂�
			CP += 2;

			// �J�[�\�����ꕶ�����i�߂�
			DrawPointX++;

			// �����҂�
			WaitTimer(10);

			// ��ʂ���͂ݏo������s����
			if (DrawPointX * moji_size + moji_size > 640) Kaigyou();

			break;
		}

		// �I���t���O���P��������I������
		if (EndFlag == 1) break;

		// �Q�ƕ�����̏I�[�܂ōs���Ă�����Q�ƕ������i�߂�
		if (Script[SP][CP] == '\0')
		{
			SP++;
			CP = 0;
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}
