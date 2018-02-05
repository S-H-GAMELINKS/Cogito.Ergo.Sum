// SaveData Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include <string>
#include <thread>
#include <chrono>

extern int Sp, Cp;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

//�e��f�ރn���h��
extern std::int32_t BackGroundHandle;
extern std::int32_t CharacterHandle;
extern std::int32_t BackGroundMusicHandle;
extern std::int32_t SoundEffectHandle;

//������`��ʒu
extern int DrawPointX, DrawPointY;

//�I���t���O
extern int EndFlag;

//temp�f�[�^
extern int EndFlagTemp, SpTemp;

namespace {

	//�e�핪��\���z��
	static constexpr const char* SaveTaskItem[] = { "�Z�[�u���܂����H", "���[�h���܂����H", "�폜���܂����H" };
	static constexpr const char* SaveTaskItemParticle[] = { "��", "��", "��" };

	//�Z�[�u�f�[�^�p�X�N���[���V���b�g�i�[�ϐ�
	std::int32_t SaveSnap[SaveDataSlotNum];

	//�ʏ�Z�[�u�f�[�^
	struct alignas(4) SaveData_t {
		std::int32_t EndFlag;    //EndFlag
		std::int32_t Sp;			//�s��
		std::int32_t Cp;			//�����ʒu
		std::int32_t Character;		//�����G���
		std::int32_t BackGround;			//�w�i�摜���
		std::int32_t BackGroundMusic;		//BGM���
	};

	//�Z�[�u�f�[�^�p�X�N���[���V���b�g�Ǎ��֐�
	void SaveDataSnapLoad() {
		std::string FilePath = "DATA/SAVE/SAVESNAP";
		std::string FileFormat = ".png";
		std::string FileName = "";

		for (std::int32_t i = 0; i < SaveDataSlotNum; i++) {

			FileName = (FilePath + std::to_string(i + 1) + FileFormat);

			SaveSnap[i] = DxLib::LoadGraph(FileName.c_str());
		}
	}

	//�Z�[�u/���[�h/�f���[�g ���j���[�`��
	void SaveLoadDeleteMenuDraw(std::int32_t& cursor_y, unsigned int color) {

		//�X�N���[���V���b�g�`��
		for (std::int32_t i = 0; i < SaveDataSlotNum; i++)
			DxLib::DrawRotaGraph(SaveSnapDrawPosX, SaveBasePosY * (i + 1), 0.2f, 0, SaveSnap[i], TRUE);

		//�J�[�\���̕`��
		DxLib::DrawString(SaveDataBasePosX, cursor_y, "��", color);

		//�Z�[�u�f�[�^���`��
		DxLib::DrawString(SaveDataNamePosX, SaveBasePosY, "�Z�[�u�f�[�^1", color);
		DxLib::DrawString(SaveDataNamePosX, SaveBasePosY * 2, "�Z�[�u�f�[�^2", color);
		DxLib::DrawString(SaveDataNamePosX, SaveBasePosY * 3, "�Z�[�u�f�[�^3", color);

		DxLib::DrawString(SaveDataNamePosX - CursorMove, SaveBasePosY * 4, "�߂�", color);
	}

	//�Z�[�u/���[�h���j���[�L�[����
	void SaveLoadMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (SaveDataPosButtom == cursor_y) ? SaveBasePosY : cursor_y + SaveDataCursorMove;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (SaveBasePosY == cursor_y) ? SaveDataPosButtom : cursor_y - SaveDataCursorMove;

		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}

	//�X�N���[���V���b�g���O�ύX
	void SaveDataScreenShotRename(const int& Num) {
		std::string FilePath = "DATA/SAVE/SAVESNAP";
		std::string FileFormat = ".png";
		std::string FileName = FilePath + std::to_string(Num) + FileFormat;

		std::rename("DATA/SAVE/SAVESNSAP_TEMP.png", FileName.c_str());
	}

	//�Z�[�u�f�[�^���Z�[�u
	int SaveDataSave(const char* SaveDataPath, const char* Message, const int& Num) {

		if (IDYES == MessageBoxYesNo(Message)) {

			SaveData_t SaveData = { EndFlagTemp, SpTemp, 0, CharacterHandle, BackGroundHandle, BackGroundMusicHandle };

			FILE *fp;

			fopen_s(&fp, SaveDataPath, "wb");//�o�C�i���t�@�C�����J��
			if (nullptr == fp) {//�G���[���N������nullptr��Ԃ�
				return 0;
			}

			fwrite(&SaveData, sizeof(SaveData), 1, fp); // SaveData_t�\���̂̒��g���o��
			fclose(fp);

			//�X�N���[���V���b�g�̖��O�ύX
			SaveDataScreenShotRename(Num);

			MessageBoxOk("�Z�[�u���܂����I");
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}
		return 0;
	}

	//�Z�[�u�f�[�^�����[�h
	int SaveDataLoad(const char* SaveDataPath, const char* Message) {

		if (IDYES == MessageBoxYesNo(Message)) {

			SaveData_t SaveData;

			FILE *fp;

			fopen_s(&fp, SaveDataPath, "rb");
			if (fp == nullptr) {
				//MessageBoxOk(ErrorMessage);
				return 0;
			}

			fread(&SaveData, sizeof(SaveData), 1, fp);
			fclose(fp);

			EndFlag = SaveData.EndFlag;
			Sp = SaveData.Sp;
			Cp = SaveData.Cp;
			CharacterHandle = SaveData.Character;
			BackGroundHandle = SaveData.BackGround;
			BackGroundMusicHandle = SaveData.BackGroundMusic;

			MessageBoxOk("���[�h���܂����I");
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

			DrawPointX = 0;
			DrawPointY = 0;
			DxLib::PlaySoundMem(BackGroundMusicHandle, DX_PLAYTYPE_LOOP);
			DxLib::DrawGraph(0, 0, BackGroundHandle, TRUE);
			DxLib::DrawGraph(150, 130, CharacterHandle, TRUE);
		}
		return 0;
	}

	//�Z�[�u�f�[�^���f���[�g
	int SaveDataDelete(const char* SaveDataPath, const char* Message) {
		if (IDYES == MessageBoxYesNo(Message)) {
			std::remove(SaveDataPath);

			MessageBoxOk("�폜���܂����I");
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}
		return 0;
	}

	//�Z�[�u/���[�h/�f���[�g�؂�ւ��֐�
	void SaveDataTask(const int& Num, const char* SaveDataPath, const char* SaveDataName, std::int32_t& SaveFlag) {

		std::string Message = SaveDataName;
		Message += SaveTaskItemParticle[Num - 1];
		Message += SaveTaskItem[Num - 1];

		//�Z�[�u
		if (Num == 1)
			SaveFlag = SaveDataSave(SaveDataPath, Message.c_str(), Num);

		//���[�h
		if (Num == 2)
			SaveFlag = SaveDataLoad(SaveDataPath, Message.c_str());

		//�f���[�g
		if (Num == 3)
			SaveFlag = SaveDataDelete(SaveDataPath, Message.c_str());
	}

	//�Z�[�u/���[�h/�f���[�g ���j���[�I������
	void SaveLoadDeleteMenuSelect(std::int32_t& cursor_y, const int& Num, std::int32_t& SaveFlag) {

		if (cursor_y == SaveBasePosY && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			SaveDataTask(Num, "DATA/SAVE/SAVEDATA1.bat", "�Z�[�u�f�[�^�P", SaveFlag);
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}


		if (cursor_y == SaveBasePosY * 2 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			SaveDataTask(Num, "DATA/SAVE/SAVEDATA2.bat", "�Z�[�u�f�[�^�Q", SaveFlag);
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}


		if (cursor_y == SaveBasePosY * 3 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			SaveDataTask(Num, "DATA/SAVE/SAVEDATA3.bat", "�Z�[�u�f�[�^�R", SaveFlag);
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}


		if (cursor_y == SaveBasePosY * 4 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {

			if (IDYES == MessageBoxYesNo("�߂�܂����H")){
				SaveFlag = 0;
				std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
		}
	}
}

//�Z�[�u�f�[�^(�Z�[�u/���[�h/�f���[�g)���[�v
void SaveDataLoop(const int& Num) {

	//�e�핪��\��
	if (IDYES == MessageBoxYesNo(SaveTaskItem[Num - 1])) {

		//�Z�[�u�f�[�^���[�v�p�t���O
		std::int32_t SaveFlag = 1;

		//�`�悳��镶����̐F
		unsigned int color = DxLib::GetColor(255, 255, 255);

		DxLib::ClearDrawScreen();
		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

		//�X�N���[���V���b�g�̓Ǎ�
		SaveDataSnapLoad();

		//�J�[�\���̏����ʒu
		std::int32_t save_y = SaveBasePosY;

		//�Z�[�u�f�[�^���[�v
		while (SaveFlag == 1) {
			ScreenClear();
			SaveLoadDeleteMenuDraw(save_y, color);
			SaveLoadMenuKeyMove(save_y);
			SaveLoadDeleteMenuSelect(save_y, Num, SaveFlag);
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
}

//�Z�[�u�f�[�^���Z�[�u(Quick)
int QuickSaveDataSave() {

	if (IDYES == MessageBoxYesNo("�N�C�b�N�Z�[�u�����s���܂����H")) {

		SaveData_t SaveData = { EndFlag, SpTemp, 0, CharacterHandle, BackGroundHandle, BackGroundMusicHandle };

		FILE *fp;

		fopen_s(&fp, "DATA/SAVE/QuickSaveData.dat", "wb");//�o�C�i���t�@�C�����J��
		if (nullptr == fp) {//�G���[���N������nullptr��Ԃ�
			return 0;
		}

		fwrite(&SaveData, sizeof(SaveData), 1, fp); // SaveData_t�\���̂̒��g���o��
		fclose(fp);

		MessageBoxOk("�Z�[�u���܂����I");
		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));
	}
	return 0;
}

//�Z�[�u�f�[�^�����[�h(Quick)
int QuickSaveDataLoad() {

	if (IDYES == MessageBoxYesNo("�N�C�b�N���[�h�����s���܂����H")) {

		SaveData_t SaveData;

		FILE *fp;

		fopen_s(&fp, "DATA/SAVE/QuickSaveData.dat", "rb");
		if (fp == nullptr) {
			//MessageBoxOk(ErrorMessage);
			return 0;
		}

		fread(&SaveData, sizeof(SaveData), 1, fp);
		fclose(fp);

		EndFlag = SaveData.EndFlag;
		Sp = SaveData.Sp;
		Cp = SaveData.Cp;
		CharacterHandle = SaveData.Character;
		BackGroundHandle = SaveData.BackGround;
		BackGroundMusicHandle = SaveData.BackGroundMusic;

		MessageBoxOk("���[�h���܂����I");
		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

		DrawPointX = 0;
		DrawPointY = 0;
		DxLib::PlaySoundMem(BackGroundMusicHandle, DX_PLAYTYPE_LOOP);
		DxLib::DrawGraph(0, 0, BackGroundHandle, TRUE);
		DxLib::DrawGraph(150, 130, CharacterHandle, TRUE);
	}
	return 0;
}

//�Z�[�u�f�[�^���Z�[�u(Continue)
int ContinueSaveDataSave(const std::int32_t& RouteNum) {

	SaveData_t SaveData = { RouteNum, SpTemp, 0, CharacterHandle, BackGroundHandle, BackGroundMusicHandle };

	FILE *fp;

	fopen_s(&fp, "DATA/SAVE/ContinueSaveData.dat", "wb");//�o�C�i���t�@�C�����J��
	if (nullptr == fp) {//�G���[���N������nullptr��Ԃ�
		return 0;
	}

	fwrite(&SaveData, sizeof(SaveData), 1, fp); // SaveData_t�\���̂̒��g���o��
	fclose(fp);

	return 0;
}

//�Z�[�u�f�[�^�����[�h(Continue)
int ContinueSaveDataLoad() {

	if (IDYES == MessageBoxYesNo("�O��v���C����������ĊJ���܂����H")) {

		SaveData_t SaveData;

		FILE *fp;

		fopen_s(&fp, "DATA/SAVE/QuickSaveData.dat", "rb");
		if (fp == nullptr) {
			//MessageBoxOk(ErrorMessage);
			return 0;
		}

		fread(&SaveData, sizeof(SaveData), 1, fp);
		fclose(fp);

		EndFlag = SaveData.EndFlag;
		Sp = SaveData.Sp;
		Cp = SaveData.Cp;
		CharacterHandle = SaveData.Character;
		BackGroundHandle = SaveData.BackGround;
		BackGroundMusicHandle = SaveData.BackGroundMusic;

		MessageBoxOk("���[�h���܂����I");
		std::this_thread::sleep_for(std::chrono::milliseconds(WaitKeyTaskTime));

		DrawPointX = 0;
		DrawPointY = 0;
		DxLib::PlaySoundMem(BackGroundMusicHandle, DX_PLAYTYPE_LOOP);
		DxLib::DrawGraph(0, 0, BackGroundHandle, TRUE);
		DxLib::DrawGraph(150, 130, CharacterHandle, TRUE);
	}
	return 0;
}

//�Z�[�u�f�[�^�p�X�N���[���V���b�g�擾
void SaveDataScreenShotGet() {
	DxLib::SaveDrawScreen(0, 0, 640, 480, "DATA/SAVE/SAVESNSAP_TEMP.png");
}