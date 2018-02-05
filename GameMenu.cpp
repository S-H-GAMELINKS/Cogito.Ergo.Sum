// GameMenu Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "SaveData.h"
#include "ConfigMenu.h"
#include "Skip_Auto.h"
#include "BackLog.h"
#include <thread>
#include <chrono>

//�I���t���O
extern int EndFlag;

//�s�Ǘ��ϐ�
extern int Sp, Cp;

//������`��ʒu
extern int DrawPointX, DrawPointY;

//temp�f�[�^
extern int EndFlagTemp, SpTemp;

//�e��f�ރn���h��
extern std::int32_t BackGroundHandle;
extern std::int32_t CharacterHandle;
extern std::int32_t BackGroundMusicHandle;
extern std::int32_t SoundEffectHandle;

namespace {
	//�Q�[�����j���[�`��֐�
	void GameMenuDraw(std::int32_t& cursor_y, unsigned int color) {

		static constexpr const char* GameMenuItem[] = {
			"�Z�[�u", "���[�h", "�Z�[�u�f�[�^�폜", "���ǃX�L�b�v", "�X�L�b�v", "�I�[�g",
			"�I�[�g/�X�L�b�v��~", "�o�b�N���O�Q��", "�ݒ�", "�^�C�g���ɖ߂�", "�Q�[���ɖ߂�", "�Q�[���I��"
		};

		//�e���j���[���ڂ̕`��
		for (std::int32_t i = 0; i < 12; i++)
			DxLib::DrawString(SaveDataNamePosX, GameMenuBasePosY * (i + 1), GameMenuItem[i], color);

		//�J�[�\���̕`��
		DxLib::DrawString(SaveBasePosX - (CursorMove * 6), cursor_y, "��", color);
	}

	//�Q�[�����j���[�L�[����
	void GameMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (GameMenuBasePosY * 12 == cursor_y) ? GameMenuBasePosY : cursor_y + GameMenuBasePosY;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (GameMenuBasePosY == cursor_y) ? GameMenuBasePosY * 12 : cursor_y - GameMenuBasePosY;

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//�Q�[���֖߂�
	void GameMenuBackToGamePlay() {
		EndFlag = EndFlagTemp;
		Sp = SpTemp;
		DrawPointX = 0;
		DrawPointY = 0;
		DxLib::PlaySoundMem(BackGroundMusicHandle, DX_PLAYTYPE_LOOP);
		DxLib::DrawGraph(0, 0, BackGroundHandle, TRUE);
		DxLib::DrawGraph(150, 130, CharacterHandle, TRUE);
	}

	//�^�C�g���֖߂�
	void GameMenuBackToTitle() {

		if (IDYES == MessageBoxYesNo("�^�C�g���ɖ߂�܂����H")) {
			EndFlag = 0;
			Sp = 0;
			Cp = 0;
			DrawPointX = 0;
			DrawPointY = 0;
			BackGroundHandle = 0;
			CharacterHandle = 0;
			BackGroundMusicHandle = 0;
			SoundEffectHandle = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//�Q�[�����j���[���ڑI������
	void GameMenuSelect(std::int32_t& cursor_y) {

		if (cursor_y == GameMenuBasePosY && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SaveDataLoop(1);

		if (cursor_y == GameMenuBasePosY * 2 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SaveDataLoop(2);

		if (cursor_y == GameMenuBasePosY * 3 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SaveDataLoop(3);

		if (cursor_y == GameMenuBasePosY && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SkipAndAutoTask(3);

		if (cursor_y == GameMenuBasePosY * 5 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SkipAndAutoTask(1);

		if (cursor_y == GameMenuBasePosY * 6 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SkipAndAutoTask(2);

		if (cursor_y == GameMenuBasePosY * 7 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SkipAndAutoTask(0);

		if (cursor_y == GameMenuBasePosY * 8 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			BackLogLoop();

		if (cursor_y == GameMenuBasePosY * 9 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			ConfigMenuLoop();

		if (cursor_y == GameMenuBasePosY * 10 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			GameMenuBackToTitle();

		if (cursor_y == GameMenuBasePosY * 11 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			GameMenuBackToGamePlay();

		if (cursor_y == GameMenuBasePosY * 12 && CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (IDYES == MessageBoxYesNo("�Q�[�����I�����܂����H"))
				EndFlag = 99;
		}

	}
}

//�Q�[�����j���[���[�v
void GameMenuLoop() {

	std::int32_t gamemenu_y = GameMenuBasePosY;
	unsigned int color = DxLib::GetColor(255, 255, 255);

	DxLib::ClearDrawScreen();

	while (EndFlag == 17) {
		ScreenClear();
		GameMenuDraw(gamemenu_y, color);
		GameMenuKeyMove(gamemenu_y);
		GameMenuSelect(gamemenu_y);

		//�Q�[���I���m�F�E�C���h�E
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			GameEndMessageBox();
	}
}