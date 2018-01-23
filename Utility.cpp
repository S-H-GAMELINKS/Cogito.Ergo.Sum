// Utility Source

#include "DxLib.h"
#include <thread>
#include <chrono>

//�Q�[���^�C�g����
extern const char* GameTitle;

//�I���t���O
extern int EndFlag;

//�L�[������~����
extern const std::int32_t wait_key_task_time;

//�Q�[���v���C���̒x������
extern const std::int32_t wait_game_time;

namespace {

	//������~���Ԍv�Z�֐�
	template <typename T>
	decltype(auto) WaitTimeCalc(const T var) {
		return var * var;
	}
}

//���b�Z�[�W�{�b�N�X(Yes or No)
int MessageBoxYesNo(LPCTSTR lpText) noexcept
{
	return MessageBox(
		DxLib::GetMainWindowHandle(),
		lpText,
		GameTitle,
		MB_YESNO
	);
}

//���b�Z�[�W�{�b�N�X(OK)
int MessageBoxOk(LPCTSTR lpText) noexcept
{
	return MessageBox(
		DxLib::GetMainWindowHandle(),
		lpText,
		GameTitle,
		MB_OK
	);
}

//��ʃN���A�����֐�
void ScreenClear() noexcept {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT);
}

//�Q�[���I���m�F�E�C���h�E
void GameEndMessageBox() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
		if (IDYES == MessageBoxYesNo("�I�����܂����H"))
			EndFlag = 99;

		if (EndFlag != 99 && EndFlag != -1)
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitTimeCalc(wait_key_task_time) / wait_game_time));
		else
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}
}