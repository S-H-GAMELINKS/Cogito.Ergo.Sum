// GameMenu Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "SaveData.h"
#include <thread>
#include <chrono>

//�I���t���O
extern int EndFlag;

//�s�Ǘ��ϐ�
extern int SP, CP;

//������`��ʒu
extern int DrawPointX, DrawPointY;

//temp�f�[�^
extern int EndFlagTemp, SP_Temp;

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
			DxLib::DrawString(save_name_pos_x, game_menu_base_pos_y * (i + 1), GameMenuItem[i], color);

		//�J�[�\���̕`��
		DxLib::DrawString(save_base_pos_x - (cursor_move * 6), cursor_y, "��", color);
	}

	//�Q�[�����j���[�L�[����
	void GameMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (game_menu_base_pos_y * 12 == cursor_y) ? game_menu_base_pos_y : cursor_y + game_menu_base_pos_y;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (game_menu_base_pos_y == cursor_y) ? game_menu_base_pos_y * 12 : cursor_y - game_menu_base_pos_y;

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//�Q�[���֖߂�
	void GameMenuBackToGamePlay() {
		EndFlag = EndFlagTemp;
		SP = SP_Temp;
		DrawPointX = 0;
		DrawPointY = 0;
		DxLib::PlaySoundMem(BackGroundMusicHandle, DX_PLAYTYPE_LOOP);
		DxLib::DrawGraph(0, 0, BackGroundHandle, TRUE);
		DxLib::DrawGraph(150, 130, CharacterHandle, TRUE);
	}

	//�Q�[�����j���[���ڑI������
	void GameMenuSelect(std::int32_t& cursor_y) {

		if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SaveDataLoop(1);

		if (cursor_y == game_menu_base_pos_y * 2 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SaveDataLoop(2);

		if (cursor_y == game_menu_base_pos_y * 3 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			SaveDataLoop(3);

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		//if (cursor_y == game_menu_base_pos_y && CheckHitKey(KEY_INPUT_RETURN) == 1)

		if (cursor_y == game_menu_base_pos_y * 11 && CheckHitKey(KEY_INPUT_RETURN) == 1)
			GameMenuBackToGamePlay();

		if (cursor_y == game_menu_base_pos_y * 12 && CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (IDYES == MessageBoxYesNo("�Q�[�����I�����܂����H"))
				EndFlag = 99;
		}

	}
}

//�Q�[�����j���[���[�v
void GameMenuLoop() {

	std::int32_t gamemenu_y = game_menu_base_pos_y;
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