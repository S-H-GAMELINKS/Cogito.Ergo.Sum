#include "DxLib.h"

//��ʃN���A�����֐�
void ScreenClear() noexcept {
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT);
}
