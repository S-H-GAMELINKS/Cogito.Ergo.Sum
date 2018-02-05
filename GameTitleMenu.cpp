// Game Title Menu Source 
#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "SaveData.h"
#include "ConfigMenu.h"
#include <thread>
#include <chrono>

//�I���t���O
extern int EndFlag;

//�^�C�g�����
extern std::int32_t GameTitleGraph;

namespace {

	//�^�C�g�����j���[�̕`��֐�
	void GameTitleMenuDraw(unsigned int Color, std::int32_t CursorPosY) {

		const char* TitleMenuItem[] = { "Start", "Load", "Config", "QuickLoad", "Continue", "Exit" };

		DxLib::DrawGraph(0, 0, GameTitleGraph, TRUE);

		//�J�[�\���̕`��
		DxLib::DrawString(title_menu_cursor_x, CursorPosY, "��", Color);

		//�e���j���[�`��
		for (std::int32_t i = 0; i < 6; i++)
			DxLib::DrawString(title_menu_x, title_menu_y + 30 * i, TitleMenuItem[i], Color);
	}

	//�^�C�g�����j���[�̃L�[����
	void GameTitleMenuKeyMove(std::int32_t& CursorPosY) {

		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			CursorPosY = (title_menu_exit_y == CursorPosY) ? title_menu_y : CursorPosY + CursorMove;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			CursorPosY = (title_menu_y == CursorPosY) ? title_menu_exit_y : CursorPosY - CursorMove;

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//�Q�[���I��(�^�C�g�����j���[)
	void GameTitleMenuExit() {
		if (IDYES == MessageBoxYesNo("�I�����܂����H"))
			EndFlag = 99;
	}

	//�^�C�g�����j���[�̍��ڑI���֐�
	void GameTitleMenuChoice(const std::int32_t& CursorPosY) {

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && CursorPosY == title_menu_y)
			EndFlag = 1;

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && CursorPosY == title_menu_load_y)
			SaveDataLoop(2);

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && CursorPosY == title_menu_config_y)
			ConfigMenuLoop();

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && CursorPosY == title_menu_quick_load_y)
			QuickSaveDataLoad();

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && CursorPosY == title_menu_continue_y)
			ContinueSaveDataLoad();

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && CursorPosY == title_menu_exit_y)
			GameTitleMenuExit();
	}
}

//�^�C�g�����j���[�̃��[�v�֐�
void GameTitleMenuLoop(unsigned int Color, std::int32_t& CursorPosY) {

	while (EndFlag == 0) {
		ScreenClear();
		GameTitleMenuDraw(Color, CursorPosY);
		GameTitleMenuKeyMove(CursorPosY);
		GameTitleMenuChoice(CursorPosY);

		//�Q�[���I���m�F�E�C���h�E
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			GameEndMessageBox();
	}
}
