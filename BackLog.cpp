// BackLog Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include <string>
#include <vector>
#include <thread>
#include <chrono>

namespace {
	std::int32_t BackLogCount = 0;
	std::vector<std::int32_t> BackLog;

	//�o�b�N���O�擾
	void BackLogGet() {
		DxLib::SetDrawScreen(DX_SCREEN_BACK);
		DxLib::SaveDrawScreenToPNG(0, 0, 640, 480, "DATA/BACKLOG/BACKLOG1.png");
		++BackLogCount;
		BackLog.emplace_back(std::move(DxLib::LoadGraph("DATA/BACKLOG/BACKLOG1.png")));
		DxLib::SetDrawScreen(DX_SCREEN_FRONT);
	}

	//�o�b�N���O�̃i���o�[�\��
	void BackLogNumberDraw(const std::int32_t& Num) {
		std::string name = "�o�b�N���O";
		name += std::to_string(Num + 1);
		DxLib::DrawString(0, 400, name.c_str(), DxLib::GetColor(255, 255, 255));
	}

	//�o�b�N���O�̕`��
	void BackLogDraw(std::int32_t& Num) {

		if (Num < BackLogCount) {
			DxLib::DrawGraph(0, 0, BackLog[Num], TRUE);
			BackLogNumberDraw(Num);
		}
		else {
			MessageBoxOk("����ȏ�o�b�O���O�͂���܂���");
			Num--;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//�o�b�N���O���̃L�[����
	void BackLogKeyMove(std::int32_t& Num, std::int32_t& BackLogFlag) {

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			Num = (Num < BackLogCount) ? Num + 1 : Num;

		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			Num = (Num > 0) ? Num - 1 : 0;

		if (DxLib::CheckHitKey(KEY_INPUT_BACK) == 1) {
			if (IDYES == MessageBoxYesNo("�o�b�N���O���I�����܂����H"))
				BackLogFlag = 0;
		}
	}
}

//�o�b�N���O���[�v
void BackLogLoop() {

	if (IDYES == MessageBoxYesNo("�o�b�N���O��\�����܂����H")) {

		if (!BackLog.empty()) {
			std::int32_t Num = 0;
			std::int32_t BackLogFlag = 1;

			while (BackLogFlag == 1) {
				BackLogDraw(Num);
				BackLogKeyMove(Num, BackLogFlag);
				ScreenClear();
			}
		}
		else
			MessageBoxOk("�o�b�N���O������܂���");
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
}
