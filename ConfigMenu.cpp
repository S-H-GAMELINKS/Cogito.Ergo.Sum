// Config Menu Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "ConfigMenu.h"
#include "MouseAndKeyState.hpp"
#include <thread>
#include <chrono>

ConfigData_t ConfigData = {
	/*BackGroundMusicVolume               :*/100,
	/*BackGroundMusicVolumeCount          :*/10,
	/*SoundEffectVolume		              :*/100,
	/*SoundEffectVolumecount              :*/10,
	/*SkipSpeedVolume		              :*/100,
	/*SkipSpeedVolumeCount			      :*/10,
	/*AutoSpeedVolume		              :*/100,
	/*AutoSpeedVolumeCount				  :*/10,
	/*ScriptDrawSpeedVolume		          :*/100,
	/*ScriptDrawSpeedVolumeCount	      :*/10,
	/*MouseAndKeyFlag;			          :*/1
};

namespace {

	static constexpr const char* ConfigMenuItem[] = {
		"ＢＧＭ音量", "ＳＥ音量", "オート速度", "スキップ速度", "文字描画速度", "マウス/キー操作", "戻る"
	};

	//コンフィグ画面描画
	void ConfigMenuDraw(std::int32_t& ConfigCursorPosY) noexcept {

		//各項目の描画
		for (std::int32_t i = 0; i < 7; i++)
			DxLib::DrawString(SaveDataNamePosX, GameMenuBasePosY * (i + 1), ConfigMenuItem[i], Color);

		DxLib::DrawString(SaveDataNamePosX - CursorMove, ConfigCursorPosY, "■", Color);

		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY, Color, "%d", ConfigData.BackGroundMusicVolume);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 2, Color, "%d", ConfigData.SoundEffectVolume);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 3, Color, "%d", ConfigData.AutoSpeedVolume);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 4, Color, "%d", ConfigData.SkipSpeedVolume);
		DxLib::DrawFormatString(SaveDataNamePosX + CursorMove * 5, GameMenuBasePosY * 5, Color, "%d", ConfigData.ScriptDrawSpeedVolume);
		DxLib::DrawString(SaveDataNamePosX + CursorMove * 8, GameMenuBasePosY * 6, ((1 == ConfigData.MouseAndKeyFlag) ? "マウス操作" : "キー操作"), Color);
	}

	//BGM音量調節
	void BackGroundMusicVolChange() noexcept {
		
		if (MouseAndKey::CheckMouseAndKeyRight()) {
			ConfigData.BackGroundMusicVolumeCount = (ConfigData.BackGroundMusicVolumeCount >= 10) ? ConfigData.BackGroundMusicVolumeCount = 10 : ConfigData.BackGroundMusicVolumeCount += 1;
			ConfigData.BackGroundMusicVolume = (ConfigData.BackGroundMusicVolumeCount >= 10) ? ConfigData.BackGroundMusicVolume = 100 : ConfigData.BackGroundMusicVolume += 10;

		}

		if (MouseAndKey::CheckMouseAndKeyLeft()) {
			ConfigData.BackGroundMusicVolumeCount = (ConfigData.BackGroundMusicVolumeCount <= 0) ? ConfigData.BackGroundMusicVolume = 0 : ConfigData.BackGroundMusicVolumeCount -= 1;
			ConfigData.BackGroundMusicVolume = (ConfigData.BackGroundMusicVolumeCount <= 0) ? ConfigData.BackGroundMusicVolumeCount = 0 : ConfigData.BackGroundMusicVolume -= 10;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//SE音量調節
	void SoundEffectVolChange() noexcept {
		if (MouseAndKey::CheckMouseAndKeyRight()) {
			ConfigData.SoundEffectVolumeCount = (ConfigData.SoundEffectVolumeCount >= 10) ? ConfigData.SoundEffectVolumeCount = 10 : ConfigData.SoundEffectVolumeCount += 1;
			ConfigData.SoundEffectVolume = (ConfigData.SoundEffectVolumeCount >= 10) ? ConfigData.SoundEffectVolume = 100 : ConfigData.SoundEffectVolume += 10;
		}

		if (MouseAndKey::CheckMouseAndKeyLeft()) {
			ConfigData.SoundEffectVolumeCount = (ConfigData.SoundEffectVolumeCount <= 0) ? ConfigData.SoundEffectVolumeCount = 0 : ConfigData.SoundEffectVolumeCount -= 1;
			ConfigData.SoundEffectVolume = (ConfigData.SoundEffectVolumeCount <= 0) ? ConfigData.SoundEffectVolume = 0 : ConfigData.SoundEffectVolume -= 10;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//オート速度調節
	void AutoSpeedVolChange() noexcept {
		if (MouseAndKey::CheckMouseAndKeyRight()) {
			ConfigData.AutoSpeedVolumeCount = (ConfigData.AutoSpeedVolumeCount >= 10) ? ConfigData.AutoSpeedVolumeCount = 10 : ConfigData.AutoSpeedVolumeCount += 1;
			ConfigData.AutoSpeedVolume = (ConfigData.AutoSpeedVolumeCount >= 10) ? ConfigData.AutoSpeedVolume = 100 : ConfigData.AutoSpeedVolume += 10;
		}

		if (MouseAndKey::CheckMouseAndKeyLeft()) {
			ConfigData.AutoSpeedVolumeCount = (ConfigData.AutoSpeedVolumeCount <= 0) ? ConfigData.AutoSpeedVolumeCount = 0 : ConfigData.AutoSpeedVolumeCount -= 1;
			ConfigData.AutoSpeedVolume = (ConfigData.AutoSpeedVolumeCount <= 0) ? ConfigData.AutoSpeedVolume = 0 : ConfigData.AutoSpeedVolume -= 10;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//スキップ速度調節
	void SkipSpeedVolChange() noexcept {
		if (MouseAndKey::CheckMouseAndKeyRight()) {
			ConfigData.SkipSpeedVolumeCount = (ConfigData.SkipSpeedVolumeCount >= 10) ? ConfigData.SkipSpeedVolumeCount = 10 : ConfigData.SkipSpeedVolumeCount += 1;
			ConfigData.SkipSpeedVolume = (ConfigData.SkipSpeedVolumeCount >= 10) ? ConfigData.SkipSpeedVolume = 100 : ConfigData.SkipSpeedVolume += 10;
		}

		if (MouseAndKey::CheckMouseAndKeyLeft()) {
			ConfigData.SkipSpeedVolumeCount = (ConfigData.SkipSpeedVolumeCount <= 0) ? ConfigData.SkipSpeedVolumeCount = 0 : ConfigData.SkipSpeedVolumeCount -= 1;
			ConfigData.SkipSpeedVolume = (ConfigData.SkipSpeedVolumeCount <= 0) ? ConfigData.SkipSpeedVolume = 0 : ConfigData.SkipSpeedVolume -= 10;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//文字列描画速度調節
	void StringDrawSpeedVolChange() noexcept {
		if (MouseAndKey::CheckMouseAndKeyRight()) {
			ConfigData.ScriptDrawSpeedVolumeCount = (ConfigData.ScriptDrawSpeedVolumeCount >= 10) ? ConfigData.ScriptDrawSpeedVolumeCount = 10 : ConfigData.ScriptDrawSpeedVolumeCount += 1;
			ConfigData.ScriptDrawSpeedVolume = (ConfigData.ScriptDrawSpeedVolumeCount >= 10) ? ConfigData.ScriptDrawSpeedVolume = 100 : ConfigData.ScriptDrawSpeedVolume += 10;
		}

		if (MouseAndKey::CheckMouseAndKeyLeft()) {
			ConfigData.ScriptDrawSpeedVolumeCount = (ConfigData.ScriptDrawSpeedVolumeCount <= 0) ? ConfigData.ScriptDrawSpeedVolumeCount = 0 : ConfigData.ScriptDrawSpeedVolumeCount -= 1;
			ConfigData.ScriptDrawSpeedVolume = (ConfigData.ScriptDrawSpeedVolumeCount <= 0) ? ConfigData.ScriptDrawSpeedVolume = 0 : ConfigData.ScriptDrawSpeedVolume -= 10;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	// マウス操作/キー操作切り替え
	void MouseAndKeyMoveChange() noexcept {
		if (MouseAndKey::CheckMouseAndKeyRight())
			ConfigData.MouseAndKeyFlag = 1;

		if (MouseAndKey::CheckMouseAndKeyLeft())
			ConfigData.MouseAndKeyFlag = 0;

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//コンフィグ画面選択処理
	bool ConfigMenuSelect(std::int32_t& ConfigCursorPosY, bool ConfigFlag) noexcept {

		if (GameMenuBasePosY == ConfigCursorPosY)
			BackGroundMusicVolChange();

		if (GameMenuBasePosY * 2 == ConfigCursorPosY)
			SoundEffectVolChange();

		if (GameMenuBasePosY * 3 == ConfigCursorPosY)
			AutoSpeedVolChange();

		if (GameMenuBasePosY * 4 == ConfigCursorPosY)
			SkipSpeedVolChange();

		if (GameMenuBasePosY * 5 == ConfigCursorPosY)
			StringDrawSpeedVolChange();

		if (GameMenuBasePosY * 6 == ConfigCursorPosY)
			MouseAndKeyMoveChange();

		if (GameMenuBasePosY * 7 == ConfigCursorPosY && MouseAndKey::CheckMouseAndKeyLeft()) {
			if (IDYES == MessageBoxYesNo("戻りますか？")) {
				ConfigFlag = false;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}

		return ConfigFlag;
	}
}

//コンフィグ読込関数
int ConfigLoad() noexcept {

	FILE *Fp;

	fopen_s(&Fp, "DATA/SAVE/Config.dat", "rb");
	if (nullptr == Fp) {
		return 0;
	}

	fread(&ConfigData, sizeof(ConfigData_t), 1, Fp);
	fclose(Fp);
	return 0;
}

//コンフィグ保存関数
int ConfigSave() noexcept {
	FILE* Fp;

	fopen_s(&Fp, "DATA/SAVE/Config.dat", "wb");//バイナリファイルを開く

	if (nullptr == Fp) {//エラーが起きたらnullptrを返す
		return 0;
	}

	fwrite(&ConfigData, sizeof(ConfigData_t), 1, Fp); // ConfigData_t構造体の中身を出力
	fclose(Fp);

	return 0;
}

//コンフィグ画面ループ
void ConfigMenuLoop() noexcept {

	if (IDYES == MessageBoxYesNo("コンフィグ画面に移行しますか？")) {

		bool ConfigFlag = true;

		std::int32_t ConfigCursorPosY = GameMenuBasePosY;

		while (ConfigFlag) {
			ScreenClear();
			ConfigMenuDraw(ConfigCursorPosY);
			ConfigCursorPosY = (ConfigData.MouseAndKeyFlag == 1) ? MouseState::ConfigMenuMouseMove(ConfigCursorPosY) : KeyState::ConfigMenuKeyMove(ConfigCursorPosY);
			ConfigFlag = ConfigMenuSelect(ConfigCursorPosY, ConfigFlag);
		}
	}
}
