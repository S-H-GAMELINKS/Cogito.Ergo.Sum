// Config Menu Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "ConfigMenu.h"
#include <thread>
#include <chrono>

ConfigData_t ConfigData = {
	/*bgm_vol               :*/100,
	/*bgm_vol_count         :*/10,
	/*se_vol                :*/100,
	/*se_vol_count          :*/10,
	/*skip_speed            :*/100,
	/*skip_speed_count      :*/10,
	/*auto_speed            :*/100,
	/*auto_speed_count      :*/10,
	/*string_speed          :*/100,
	/*string_speed_count    :*/10,
	/*mouse_key_move        :*/1
};

namespace {

	static constexpr const char* ConfigMenuItem[] = {
		"�a�f�l����", "�r�d����", "�I�[�g���x", "�X�L�b�v���x", "�����`�摬�x", "�}�E�X/�L�[����", "�߂�"
	};

	//�R���t�B�O��ʕ`��
	void ConfigMenuDraw(std::int32_t& cursor_y) {

		//�e���ڂ̕`��
		for (std::int32_t i = 0; i < 7; i++)
			DxLib::DrawString(save_name_pos_x, game_menu_base_pos_y * (i + 1), ConfigMenuItem[i], 255);

		DxLib::DrawString(save_name_pos_x - cursor_move, cursor_y, "��", 255);

		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y, 255, "%d", ConfigData.bgm_vol);
		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y * 2, 255, "%d", ConfigData.se_vol);
		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y * 3, 255, "%d", ConfigData.auto_speed);
		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y * 4, 255, "%d", ConfigData.skip_speed);
		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y * 5, 255, "%d", ConfigData.string_speed);
		DxLib::DrawString(save_name_pos_x + cursor_move * 8, game_menu_base_pos_y * 6, ((1 == ConfigData.mouse_key_move) ? "�}�E�X����" : "�L�[����"), 255);
	}

	//�R���t�B�O��ʃL�[����
	void ConfigMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (game_menu_base_pos_y * 7 == cursor_y) ? game_menu_base_pos_y : cursor_y + cursor_move;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (game_menu_base_pos_y == cursor_y) ? game_menu_base_pos_y * 7 : cursor_y - cursor_move;

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//BGM���ʒ���
	void BackGroundMusicVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.bgm_vol += 10;
			ConfigData.bgm_vol_count += 1;

			if (ConfigData.bgm_vol_count >= 10) {
				ConfigData.bgm_vol = 100;
				ConfigData.bgm_vol_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.bgm_vol -= 10;
			ConfigData.bgm_vol_count -= 1;

			if (ConfigData.bgm_vol_count <= 0) {
				ConfigData.bgm_vol = 0;
				ConfigData.bgm_vol_count = 0;
			}
		}
	}

	//SE���ʒ���
	void SoundEffectVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.se_vol += 10;
			ConfigData.se_vol_count += 1;

			if (ConfigData.se_vol_count >= 10) {
				ConfigData.se_vol = 100;
				ConfigData.se_vol_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.se_vol -= 10;
			ConfigData.se_vol_count -= 1;

			if (ConfigData.se_vol_count <= 0) {
				ConfigData.se_vol = 0;
				ConfigData.se_vol_count = 0;
			}
		}
	}

	//�I�[�g���x����
	void AutoSpeedVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.auto_speed += 10;
			ConfigData.auto_speed_count += 1;

			if (ConfigData.auto_speed_count >= 10) {
				ConfigData.auto_speed = 100;
				ConfigData.auto_speed_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.auto_speed -= 10;
			ConfigData.auto_speed_count -= 1;

			if (ConfigData.auto_speed_count <= 0) {
				ConfigData.auto_speed = 0;
				ConfigData.auto_speed_count = 0;
			}
		}
	}

	//�X�L�b�v���x����
	void SkipSpeedVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.skip_speed += 10;
			ConfigData.skip_speed_count += 1;

			if (ConfigData.skip_speed_count >= 10) {
				ConfigData.skip_speed = 100;
				ConfigData.skip_speed_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.skip_speed -= 10;
			ConfigData.skip_speed_count -= 1;

			if (ConfigData.skip_speed_count <= 0) {
				ConfigData.skip_speed = 0;
				ConfigData.skip_speed_count = 0;
			}
		}
	}

	//������`�摬�x����
	void StringDrawSpeedVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.string_speed += 10;
			ConfigData.string_speed_count += 1;

			if (ConfigData.string_speed_count >= 10) {
				ConfigData.string_speed = 100;
				ConfigData.string_speed_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.string_speed -= 10;
			ConfigData.string_speed_count -= 1;

			if (ConfigData.string_speed_count <= 0) {
				ConfigData.string_speed = 0;
				ConfigData.string_speed_count = 0;
			}
		}
	}

	// �}�E�X����/�L�[����؂�ւ�
	void MouseAndKeyMoveChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
			ConfigData.mouse_key_move = 1;
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
			ConfigData.mouse_key_move = 0;
		}
	}

	//�R���t�B�O��ʑI������
	void ConfigMenuSelect(std::int32_t& cursor_y, std::int32_t& ConfigFlag) {

		if (game_menu_base_pos_y == cursor_y)
			BackGroundMusicVolChange();

		if (game_menu_base_pos_y * 2 == cursor_y)
			SoundEffectVolChange();

		if (game_menu_base_pos_y * 3 == cursor_y)
			AutoSpeedVolChange();

		if (game_menu_base_pos_y * 4 == cursor_y)
			SkipSpeedVolChange();

		if (game_menu_base_pos_y * 5 == cursor_y)
			StringDrawSpeedVolChange();

		if (game_menu_base_pos_y * 6 == cursor_y)
			MouseAndKeyMoveChange();

		if (game_menu_base_pos_y * 7 == cursor_y && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (IDYES == MessageBoxYesNo("�߂�܂����H")) {
				ConfigFlag = 0;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}
	}
}

//�R���t�B�O��ʃ��[�v
void ConfigMenuLoop() {

	if (IDYES == MessageBoxYesNo("�R���t�B�O��ʂɈڍs���܂����H")) {

		std::int32_t ConfigFlag = 1;

		std::int32_t config_y = game_menu_base_pos_y;

		while (ConfigFlag == 1) {
			ScreenClear();
			ConfigMenuDraw(config_y);
			ConfigMenuKeyMove(config_y);
			ConfigMenuSelect(config_y, ConfigFlag);
		}
	}
}
