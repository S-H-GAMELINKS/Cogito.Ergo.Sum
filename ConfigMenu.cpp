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
			DxLib::DrawString(SaveDataNamePosX, GameMenuBasePosY * (i + 1), ConfigMenuItem[i], 255);

		DxLib::DrawString(SaveDataNamePosX - CursorMove, cursor_y, "��", 255);

		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY, 255, "%d", ConfigData.bgm_vol);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 2, 255, "%d", ConfigData.se_vol);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 3, 255, "%d", ConfigData.auto_speed);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 4, 255, "%d", ConfigData.skip_speed);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 5, 255, "%d", ConfigData.string_speed);
		DxLib::DrawString(SaveDataNamePosX + CursorMove * 8, GameMenuBasePosY * 6, ((1 == ConfigData.mouse_key_move) ? "�}�E�X����" : "�L�[����"), 255);
	}

	//�R���t�B�O��ʃL�[����
	void ConfigMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (GameMenuBasePosY * 7 == cursor_y) ? GameMenuBasePosY : cursor_y + CursorMove;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (GameMenuBasePosY == cursor_y) ? GameMenuBasePosY * 7 : cursor_y - CursorMove;

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//BGM���ʒ���
	void BackGroundMusicVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

			ConfigData.bgm_vol += 10;
			ConfigData.bgm_vol_count += 1;

			if (ConfigData.bgm_vol_count >= 10) {
				ConfigData.bgm_vol = 100;
				ConfigData.bgm_vol_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

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
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

			ConfigData.se_vol += 10;
			ConfigData.se_vol_count += 1;

			if (ConfigData.se_vol_count >= 10) {
				ConfigData.se_vol = 100;
				ConfigData.se_vol_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

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
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

			ConfigData.auto_speed += 10;
			ConfigData.auto_speed_count += 1;

			if (ConfigData.auto_speed_count >= 10) {
				ConfigData.auto_speed = 100;
				ConfigData.auto_speed_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

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
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

			ConfigData.skip_speed += 10;
			ConfigData.skip_speed_count += 1;

			if (ConfigData.skip_speed_count >= 10) {
				ConfigData.skip_speed = 100;
				ConfigData.skip_speed_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

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
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

			ConfigData.string_speed += 10;
			ConfigData.string_speed_count += 1;

			if (ConfigData.string_speed_count >= 10) {
				ConfigData.string_speed = 100;
				ConfigData.string_speed_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

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
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
			ConfigData.mouse_key_move = 1;
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
			ConfigData.mouse_key_move = 0;
		}
	}

	//�R���t�B�O��ʑI������
	void ConfigMenuSelect(std::int32_t& cursor_y, std::int32_t& ConfigFlag) {

		if (GameMenuBasePosY == cursor_y)
			BackGroundMusicVolChange();

		if (GameMenuBasePosY * 2 == cursor_y)
			SoundEffectVolChange();

		if (GameMenuBasePosY * 3 == cursor_y)
			AutoSpeedVolChange();

		if (GameMenuBasePosY * 4 == cursor_y)
			SkipSpeedVolChange();

		if (GameMenuBasePosY * 5 == cursor_y)
			StringDrawSpeedVolChange();

		if (GameMenuBasePosY * 6 == cursor_y)
			MouseAndKeyMoveChange();

		if (GameMenuBasePosY * 7 == cursor_y && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (IDYES == MessageBoxYesNo("�߂�܂����H")) {
				ConfigFlag = 0;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}
	}
}

//�R���t�B�O�Ǎ��֐�
int ConfigLoad() {

	FILE *fp;

	fopen_s(&fp, "DATA/SAVE/Config.dat", "rb");
	if (nullptr == fp) {
		return 0;
	}

	fread(&ConfigData, sizeof(ConfigData_t), 1, fp);
	fclose(fp);
	return 0;
}

//�R���t�B�O�ۑ��֐�
int ConfigSave() {
	FILE* fp;

	fopen_s(&fp, "DATA/SAVE/Config.dat", "wb");//�o�C�i���t�@�C�����J��

	if (nullptr == fp) {//�G���[���N������nullptr��Ԃ�
		return 0;
	}

	fwrite(&ConfigData, sizeof(ConfigData_t), 1, fp); // ConfigData_t�\���̂̒��g���o��
	fclose(fp);

	return 0;
}

//�R���t�B�O��ʃ��[�v
void ConfigMenuLoop() {

	if (IDYES == MessageBoxYesNo("�R���t�B�O��ʂɈڍs���܂����H")) {

		std::int32_t ConfigFlag = 1;

		std::int32_t config_y = GameMenuBasePosY;

		while (ConfigFlag == 1) {
			ScreenClear();
			ConfigMenuDraw(config_y);
			ConfigMenuKeyMove(config_y);
			ConfigMenuSelect(config_y, ConfigFlag);
		}
	}
}
