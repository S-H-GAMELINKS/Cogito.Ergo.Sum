//Script Tag Task Maneger Source
#include "DxLib.h"
#include <vector>
#include <string>
#include <array>

extern int DrawPointX, DrawPointY;	// ������`��̈ʒu
extern int SP, CP;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

//�����T�C�Y
extern const std::int32_t moji_size;

//�I���t���O
extern int EndFlag;

namespace ScriptTask {

	char OneMojiBuf[3];	// �P�������ꎞ�L���z��

	// ���s�֐�
	void Kaigyou()
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
	}

	//������`��֐�
	void DrawScript(const std::vector<std::string>& Script) {
		// �P�����������o��
		OneMojiBuf[0] = Script[SP][CP];
		OneMojiBuf[1] = Script[SP][CP + 1];
		OneMojiBuf[2] = '\0';

		// �P�����`��
		DrawString(DrawPointX * moji_size, DrawPointY * moji_size, OneMojiBuf, GetColor(255, 255, 255));

		// �Q�ƕ����ʒu���Q�o�C�g���߂�
		CP += 2;

		// �J�[�\�����ꕶ�����i�߂�
		DrawPointX++;

		// �����҂�
		WaitTimer(10);
	}

	//�w�i�摜�`��֐�
	void DrawBackGround(const std::vector<std::string>& Script, const std::array<int, 99>& BackGround) {
		CP++;
		DxLib::DrawGraph(0, 0, BackGround[(static_cast<int>(Script[SP][CP]) - 48) * 10 + (static_cast<int>(Script[SP][CP + 1]) - 48) - 1], TRUE);
	}

	//�����G�`��֐�
	void DrawCharacter(const std::vector<std::string>& Script, const std::array<int, 99>& Character) {
		CP++;
		DxLib::DrawGraph(150, 130, Character[(static_cast<int>(Script[SP][CP]) - 48) * 10 + (static_cast<int>(Script[SP][CP + 1]) - 48) - 1], TRUE);
	}

	//BGM�Đ��֐�
	void PlayBackGroundMusic(const std::vector<std::string>& Script, const std::array<int, 99>& BackGroundMusic) {
		CP++;
		DxLib::PlaySoundMem(BackGroundMusic[(static_cast<int>(Script[SP][CP]) - 48) * 10 + (static_cast<int>(Script[SP][CP + 1]) - 48) - 1], DX_PLAYTYPE_LOOP);
	}

	//���ʉ��Đ��֐�
	void PlaySoundEffect(const std::vector<std::string>& Script, const std::array<int, 99>& SoundEffect) {
		CP++;
		DxLib::PlaySoundMem(SoundEffect[(static_cast<int>(Script[SP][CP]) - 48) * 10 + (static_cast<int>(Script[SP][CP + 1]) - 48) - 1], DX_PLAYTYPE_BACK);
	}

	//����Đ��֐�
	template <typename T>
	void PlayMovie(const std::vector<T>& Script, std::array<T, 99> Movie) {
		CP++;
		DxLib::PlayMovie(Movie[(static_cast<int>(Script[SP][CP]) - 48) * 10 + (static_cast<int>(Script[SP][CP + 1]) - 48)].c_str(), 1, DX_MOVIEPLAYTYPE_BCANCEL);
	}
}

//�X�N���v�g�^�O�����֐�
void ScriptTagTaskManager(const std::vector<std::string>& Script, const std::array<int, 99>& BackGround, const std::array<int, 99>& Character, const std::array<int, 99>& BackGroundMusic, const std::array<int, 99>& SoundEffect, const std::array<std::string, 99>& Movie) {

	switch (Script[SP][CP])
	{
	case 'B':
		ScriptTask::DrawBackGround(Script, BackGround);
		break;

	case 'C':
		ScriptTask::DrawCharacter(Script, Character);
		break;

	case 'M':
		ScriptTask::PlayBackGroundMusic(Script, BackGroundMusic);
		break;

	case 'S':
		ScriptTask::PlaySoundEffect(Script, SoundEffect);
		break;

	case 'V':
		ScriptTask::PlayMovie(Script, Movie);
		break;

	case 'L':	// ���s����

				// ���s��������юQ�ƕ����ʒu����i�߂�
		ScriptTask::Kaigyou();
		CP++;

		break;

	case 'P':	// �{�^�������҂�����

				// �{�^�������҂�����юQ�ƕ����ʒu����i�߂�
		WaitKey();
		CP++;

		break;

	case 'E':	// �I������

				// �I���t���O�𗧂Ă邨��юQ�ƕ����ʒu����i�߂�
		EndFlag = 1;
		CP++;

		break;

	case 'R':	// �N���A����

				// ��ʂ����������ĕ`�敶���ʒu�������ʒu�ɖ߂�����юQ�ƕ����ʒu����i�߂�
		ClearDrawScreen();
		DrawPointY = 0;
		DrawPointX = 0;
		CP++;
		break;

	case '/':
		CP++;

		if (Script[SP][CP] == '/') {
			CP = 0;
			SP++;
		}
		break;

	case '@':
		CP++;
		break;

	case '#':
		CP++;
		break;

	case ' ':
		CP++;
		break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		CP++;
		break;

	default:	// ���̑��̕���

		//������`��
		ScriptTask::DrawScript(Script);

		// ��ʂ���͂ݏo������s����
		if (DrawPointX * moji_size + moji_size > 640) ScriptTask::Kaigyou();

		break;
	}
}