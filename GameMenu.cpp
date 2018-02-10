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

extern ConfigData_t ConfigData;

namespace {
	//�Q�[�����j���[�`��֐�
	void GameMenuDraw(std::int32_t& GameMenuCursorPosY) noexcept {

		static constexpr const char* GameMenuItem[] = {
			"�Z�[�u", "���[�h", "�Z�[�u�f�[�^�폜", "���ǃX�L�b�v", "�X�L�b�v", "�I�[�g",
			"�I�[�g/�X�L�b�v��~", "�o�b�N���O�Q��", "�ݒ�", "�^�C�g���ɖ߂�", "�Q�[���ɖ߂�", "�Q�[���I��"
		};

		//�e���j���[���ڂ̕`��
		for (std::int32_t i = 0; i < 12; i++)
			DxLib::DrawString(SaveDataNamePosX, GameMenuBasePosY * (i + 1), GameMenuItem[i], Color);

		//�J�[�\���̕`��
		DxLib::DrawString(SaveDataBasePosX - (CursorMove * 6), GameMenuCursorPosY, "��", Color);
	}

	//�Q�[�����j���[�L�[����
	void GameMenuKeyMove(std::int32_t& GameMenuCursorPosY) noexcept {
		if (ConfigData.MouseAndKeyFlag == 0) {
			if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
				GameMenuCursorPosY = (GameMenuBasePosY * 12 == GameMenuCursorPosY) ? GameMenuBasePosY : GameMenuCursorPosY + GameMenuBasePosY;

			if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
				GameMenuCursorPosY = (GameMenuBasePosY == GameMenuCursorPosY) ? GameMenuBasePosY * 12 : GameMenuCursorPosY - GameMenuBasePosY;

			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}
	}

	//�Q�[�����j���[�̃}�E�X����
	void GameMenuMouseMove(std::int32_t& GameMenuCursorPosY) noexcept {

		std::int32_t MousePosY, MousePosX;

		DxLib::GetMousePoint(&MousePosX, &MousePosY);

		if (ConfigData.MouseAndKeyFlag == 1) {
			GameMenuCursorPosY = (MousePosY <= (GameMenuBasePosY * 2) - 1) ? GameMenuBasePosY
				: (MousePosY <= (GameMenuBasePosY * 3) - 1) ? (GameMenuBasePosY * 2)
				: (MousePosY <= (GameMenuBasePosY * 4) - 1) ? (GameMenuBasePosY * 3)
				: (MousePosY <= (GameMenuBasePosY * 5) - 1) ? (GameMenuBasePosY * 4)
				: (MousePosY <= (GameMenuBasePosY * 6) - 1) ? (GameMenuBasePosY * 5)
				: (MousePosY <= (GameMenuBasePosY * 7) - 1) ? (GameMenuBasePosY * 6)
				: (MousePosY <= (GameMenuBasePosY * 8) - 1) ? (GameMenuBasePosY * 7)
				: (MousePosY <= (GameMenuBasePosY * 9) - 1) ? (GameMenuBasePosY * 8)
				: (MousePosY <= (GameMenuBasePosY * 10) - 1) ? (GameMenuBasePosY * 9)
				: (MousePosY <= (GameMenuBasePosY * 11) - 1) ? (GameMenuBasePosY * 10)
				: (MousePosY <= (GameMenuBasePosY * 12) - 1) ? (GameMenuBasePosY * 11)
				: (GameMenuBasePosY * 12);
		}
	}

	//�Q�[���֖߂�
	void GameMenuBackToGamePlay() noexcept {
		EndFlag = EndFlagTemp;
		Sp = SpTemp;
		DrawPointX = 0;
		DrawPointY = 0;
		DxLib::PlaySoundMem(BackGroundMusicHandle, DX_PLAYTYPE_LOOP);
		DxLib::DrawGraph(0, 0, BackGroundHandle, TRUE);
		DxLib::DrawGraph(150, 130, CharacterHandle, TRUE);
	}

	//�^�C�g���֖߂�
	void GameMenuBackToTitle() noexcept {

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
	void GameMenuSelect(std::int32_t& GameMenuCursorPosY) noexcept {

		if ((GameMenuCursorPosY == GameMenuBasePosY && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SaveDataLoop(1);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 2 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 2 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SaveDataLoop(2);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 3 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 3 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SaveDataLoop(3);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 4 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 4 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SkipAndAutoTask(3);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 5 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 5 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SkipAndAutoTask(1);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 6 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 6 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SkipAndAutoTask(2);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 7 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 7 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			SkipAndAutoTask(0);

		if ((GameMenuCursorPosY == GameMenuBasePosY * 8 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 8 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			BackLogLoop();

		if ((GameMenuCursorPosY == GameMenuBasePosY * 9 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 9 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			ConfigMenuLoop();

		if ((GameMenuCursorPosY == GameMenuBasePosY * 10 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 10 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			GameMenuBackToTitle();

		if ((GameMenuCursorPosY == GameMenuBasePosY * 11 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 11 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1))
			GameMenuBackToGamePlay();

		if ((GameMenuCursorPosY == GameMenuBasePosY * 12 && ConfigData.MouseAndKeyFlag == 0 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) || (GameMenuCursorPosY == GameMenuBasePosY * 12 && ConfigData.MouseAndKeyFlag == 1 && (DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) == 1)) {
			if (IDYES == MessageBoxYesNo("�Q�[�����I�����܂����H"))
				EndFlag = 99;
		}
	}
}

//�Q�[�����j���[���[�v
void GameMenuLoop() noexcept {

	std::int32_t GameMenuCursorPosY = GameMenuBasePosY;

	DxLib::ClearDrawScreen();

	while (EndFlag == 17) {
		ScreenClear();
		GameMenuDraw(GameMenuCursorPosY);
		GameMenuKeyMove(GameMenuCursorPosY);
		GameMenuMouseMove(GameMenuCursorPosY);
		GameMenuSelect(GameMenuCursorPosY);

		//�Q�[���I���m�F�E�C���h�E
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			GameEndMessageBox();
	}
}