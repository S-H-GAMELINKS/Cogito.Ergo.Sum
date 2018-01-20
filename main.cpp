// Novel Game Engine LINKS for C++
// Coding by S.H.(GAMELINKS)

#include "DxLib.h"
#include <vector>
#include <string>
#include <fstream>

// �����̃T�C�Y
#define MOJI_SIZE 24

int DrawPointX, DrawPointY;	// ������`��̈ʒu
int SP, CP;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

char String[][256] =
{
	"�@�Q�[���v���O�����Ƃ́A����v���O�����Ƃ�" ,
	"���鎖������������v���O�����̕��@���������Ă������ł��Ȃ����Ƃ�����BB" ,
	"@�@�Ȃ��Ȃ炻�̃v���O�����Z�@�������̊�{�I�ȋZ�@�̑g�ݍ��킹�ŏo���Ă��邩�炾�BB",
	"@�@����͂��̑��̊w�����{���킩��Ȃ��Ɖ��p�������Ȃ��Ƃ������ƂƓ������ۂŁA",
	"�ʂɓ��ɒ��������Ƃł��Ȃ��BB" ,
	"C�@�������Q�[���v���O�����ƂȂ�Ɗo���Ȃ��Ă͂Ȃ�Ȃ���b����R����A" ,
	"����ɂ�����x�N�I���e�B�̍����\�t�g����낤�Ƃ���ƐF�X�ȃv���O�����Z�@��",
	"�K�����Ȃ��Ă͂Ȃ�Ȃ��BB" ,
	"@�@������������x���x���������Ȃ�Ǝ����ŋZ�@��҂ݏo�����A�Z�p���x���̍���",
	"�v���O���}�[�ɕ����Ȃǂ��邵�����@���Ȃ���ϖ��ł���BB"
	"�Ƃ��������̂����ŃQ�[���v���O�����̕~���͍����Ȃ��Ă���Ƃ�����BBE"
};

// ���s�֐�
int Kaigyou(void)
{
	int TempGraph;

	// �`��s�ʒu���������
	DrawPointY++;

	// �`�����ŏ��ɖ߂�
	DrawPointX = 0;

	// ������ʂ���͂ݏo��Ȃ��ʂ��X�N���[��������
	if (DrawPointY * MOJI_SIZE + MOJI_SIZE > 480)
	{
		// �e���|�����O���t�B�b�N�̍쐬
		TempGraph = MakeGraph(640, 480);

		// ��ʂ̓��e���ہX�R�s�[����
		GetDrawScreenGraph(0, 0, 640, 480, TempGraph);

		// ��s����ɓ\��t����
		DrawGraph(0, -MOJI_SIZE, TempGraph, FALSE);

		// ��ԉ��̍s�̕��������Ŗ��߂�
		DrawBox(0, 480 - MOJI_SIZE, 640, 480, 0, TRUE);

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
	SetFontSize(MOJI_SIZE);

	// �I���t���O��|��
	EndFlag = 0;

	// ���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		char  Moji;

		// �����̕`��
		Moji = String[SP][CP];
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
			OneMojiBuf[0] = String[SP][CP];
			OneMojiBuf[1] = String[SP][CP + 1];
			OneMojiBuf[2] = '\0';

			// �P�����`��
			DrawString(DrawPointX * MOJI_SIZE, DrawPointY * MOJI_SIZE,
				OneMojiBuf, GetColor(255, 255, 255));

			// �Q�ƕ����ʒu���Q�o�C�g���߂�
			CP += 2;

			// �J�[�\�����ꕶ�����i�߂�
			DrawPointX++;

			// �����҂�
			WaitTimer(10);

			// ��ʂ���͂ݏo������s����
			if (DrawPointX * MOJI_SIZE + MOJI_SIZE > 640) Kaigyou();

			break;
		}

		// �I���t���O���P��������I������
		if (EndFlag == 1) break;

		// �Q�ƕ�����̏I�[�܂ōs���Ă�����Q�ƕ������i�߂�
		if (String[SP][CP] == '\0')
		{
			SP++;
			CP = 0;
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}
