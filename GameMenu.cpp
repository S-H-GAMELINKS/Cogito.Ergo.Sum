// GameMenu Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include <thread>
#include <chrono>

//�I���t���O
extern int EndFlag;

namespace {
	//�Q�[�����j���[�`��֐�
	void GameMenuDraw(std::int32_t& cursor_y) {

		static constexpr const char* GameMenuItem[] = {
			"�Z�[�u", "���[�h", "�Z�[�u�f�[�^�폜", "���ǃX�L�b�v", "�X�L�b�v", "�I�[�g",
			"�I�[�g/�X�L�b�v��~", "�o�b�N���O�Q��", "�ݒ�", "�^�C�g���ɖ߂�", "�Q�[���ɖ߂�", "�Q�[���I��"
		};

		//�e���j���[���ڂ̕`��
		for (std::int32_t i = 0; i < 12; i++)
			DxLib::DrawString(save_name_pos_x, game_menu_base_pos_y * (i + 1), GameMenuItem[i], 255);

		//�J�[�\���̕`��
		DxLib::DrawString(save_base_pos_x - (cursor_move * 6), cursor_y, "��", 255);
	}

	//�Q�[�����j���[�L�[����
	void GameMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (game_menu_base_pos_y * 12 == cursor_y) ? game_menu_base_pos_y : cursor_y + game_menu_base_pos_y;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (game_menu_base_pos_y == cursor_y) ? game_menu_base_pos_y * 12 : cursor_y - game_menu_base_pos_y;

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//�Q�[�����j���[���ڑI������
	void GameMenuSelect(std::int32_t& cursor_y) {

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

	}
}

//�Q�[�����j���[���[�v
void GameMenuLoop() {

	std::int32_t gamemenu_y = game_menu_base_pos_y;

	while (EndFlag == 17) {
		GameMenuDraw(gamemenu_y);
		GameMenuKeyMove(gamemenu_y);
		GameMenuSelect(gamemenu_y);
		ScreenClear();

		//�Q�[���I���m�F�E�C���h�E
		GameEndMessageBox();
	}
}