// Skip Auto Source

#include "DxLib.h"
#include "Utility.h"
#include "ConstantExpressionVariable.h"
#include <thread>
#include <chrono>

// ���ǃX�L�b�v/�X�L�b�v/�I�[�g�ϐ�
extern int SkipAndAutoFlag;

// ���ǃX�L�b�v/�X�L�b�v/�I�[�g�؂�ւ��֐�
void SkipAndAutoTask(const std::int32_t& Num) {

	if (Num == 0) {
		if (IDYES == MessageBoxYesNo("�I�[�g/�X�L�b�v���~���܂����H")) {
			SkipAndAutoFlag = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	if (Num == 1) {
		if (IDYES == MessageBoxYesNo("�X�L�b�v�����s���܂����H")) {
			SkipAndAutoFlag = 1;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	if (Num == 2) {
		if (IDYES == MessageBoxYesNo("�I�[�g�����s���܂����H")) {
			SkipAndAutoFlag = 2;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}
}
