// Game Title Menu Source 
#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "SaveData.h"
#include <thread>
#include <chrono>

//�I���t���O
extern int EndFlag;

//�^�C�g�����
extern std::int32_t GameTitleGraph;

static constexpr const char* ConfigMenuItem[] = {
	"�a�f�l����", "�r�d����", "�I�[�g���x", "�X�L�b�v���x", "�����`�摬�x", "�`����@", "�}�E�X/�L�[����", "�߂�"
};

//�R���t�B�O��ʕ`��
void ConfigMenuDraw(std::int32_t& cursor_y) {

	//�e���ڂ̕`��
	for (std::int32_t i = 0; i < 8; i++)
		DxLib::DrawString(save_name_pos_x, game_menu_base_pos_y * (i + 1), ConfigMenuItem[i], 255);

	DxLib::DrawString(save_name_pos_x - cursor_move, cursor_y, "��", 255);
}

//�R���t�B�O��ʃL�[����
void ConfigMenuKeyMove(std::int32_t& cursor_y) {
	if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
		cursor_y = (game_menu_base_pos_y * 8 == cursor_y) ? game_menu_base_pos_y : cursor_y + cursor_move;

	if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
		cursor_y = (game_menu_base_pos_y == cursor_y) ? game_menu_base_pos_y * 8 : cursor_y - cursor_move;

	std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
}

//�R���t�B�O��ʃ��[�v
void ConfigMenuLoop() {

	std::int32_t ConfigFlag = 1;

	std::int32_t config_y = game_menu_base_pos_y;

	while (ConfigFlag == 1) {
		ScreenClear();
		ConfigMenuDraw(config_y);
		ConfigMenuKeyMove(config_y);
	}

}

namespace {

	//�^�C�g�����j���[�̕`��֐�
	void GameTitleMenuDraw(unsigned int color, std::int32_t cursor_y) {

		const char* TitleMenuItem[] = { "Start", "Load", "Config", "QuickLoad", "Continue", "Exit" };

		DxLib::DrawGraph(0, 0, GameTitleGraph, TRUE);

		//�J�[�\���̕`��
		DxLib::DrawString(title_menu_cursor_x, cursor_y, "��", color);

		//�e���j���[�`��
		for (std::int32_t i = 0; i < 6; i++)
			DxLib::DrawString(title_menu_x, title_menu_y + 30 * i, TitleMenuItem[i], color);
	}

	//�^�C�g�����j���[�̃L�[����
	void GameTitleMenuKeyMove(std::int32_t& cursor_y) {

		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (title_menu_exit_y == cursor_y) ? title_menu_y : cursor_y + cursor_move;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (title_menu_y == cursor_y) ? title_menu_exit_y : cursor_y - cursor_move;

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//�Q�[���I��(�^�C�g�����j���[)
	void GameTitleMenuExit() {
		if (IDYES == MessageBoxYesNo("�I�����܂����H"))
			EndFlag = 99;
	}

	//�^�C�g�����j���[�̍��ڑI���֐�
	void GameTitleMenuChoice(const std::int32_t& cursor_y) {

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && cursor_y == title_menu_y)
			EndFlag = 1;

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && cursor_y == title_menu_load_y)
			SaveDataLoop(2);

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && cursor_y == title_menu_config_y)
			ConfigMenuLoop();

		//if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && cursor_y == title_menu_quick_load_y)

		//if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && cursor_y == title_menu_continue_y)

		if (DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1 && cursor_y == title_menu_exit_y)
			GameTitleMenuExit();
	}
}

//�^�C�g�����j���[�̃��[�v�֐�
void GameTitleMenuLoop(unsigned int color, std::int32_t& cursor_y) {

	while (EndFlag == 0) {
		ScreenClear();
		GameTitleMenuDraw(color, cursor_y);
		GameTitleMenuKeyMove(cursor_y);
		GameTitleMenuChoice(cursor_y);

		//�Q�[���I���m�F�E�C���h�E
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			GameEndMessageBox();
	}
}
