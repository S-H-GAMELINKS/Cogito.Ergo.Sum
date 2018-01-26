// SaveData Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include <string>
#include <thread>
#include <chrono>

extern int SP, CP;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

//�e��f�ރn���h��
extern std::int32_t BackGroundHandle;
extern std::int32_t CharacterHandle;
extern std::int32_t BackGroundMusicHandle;

//�I���t���O
extern int EndFlag;

namespace {

	//�e�핪��\���z��
	static constexpr const char* SaveTaskItem[] = { "�Z�[�u���܂����H", "���[�h���܂����H", "�폜���܂����H" };
	static constexpr const char* SaveTaskItemParticle[] = { "��", "��", "��" };

	//�Z�[�u�f�[�^�p�X�N���[���V���b�g�i�[�ϐ�
	std::int32_t SaveSnap[save_max_num];

	//�ʏ�Z�[�u�f�[�^
	struct alignas(4) SaveData_t {
		std::int32_t ENDFLAG;    //ENDFLAG
		std::int32_t SP;			//�s��
		std::int32_t CP;			//�����ʒu
		std::int32_t CHAR;		//�����G���
		std::int32_t BG;			//�w�i�摜���
		std::int32_t BGM;		//BGM���
	};

	//�Z�[�u�f�[�^�p�X�N���[���V���b�g�Ǎ��֐�
	void SaveDataSnapLoad() {
		std::string FilePath = "DATA/SAVE/SAVESNAP";
		std::string FileFormat = ".png";
		std::string FileName = "";

		for (std::int32_t i = 0; i < save_max_num; i++) {

			FileName = (FilePath + std::to_string(i) + FileFormat);

			SaveSnap[i] = DxLib::LoadGraph(FileName.c_str());
		}
	}

	//�Z�[�u/���[�h/�f���[�g ���j���[�`��
	void SaveLoadDeleteMenuDraw(std::int32_t& cursor_y) {

		//�X�N���[���V���b�g�`��
		for (std::int32_t i = 0; i < save_max_num; i++)
			DxLib::DrawRotaGraph(save_snap_draw_pos_x, save_base_pos_y * (i + 1), 0.2f, 0, SaveSnap[i - 1], TRUE);

		//�J�[�\���̕`��
		DxLib::DrawString(save_base_pos_x, cursor_y, "��", 255);

		//�Z�[�u�f�[�^���`��
		DxLib::DrawString(save_name_pos_x, save_base_pos_y, "�Z�[�u�f�[�^1", 255);
		DxLib::DrawString(save_name_pos_x, save_base_pos_y * 2, "�Z�[�u�f�[�^2", 255);
		DxLib::DrawString(save_name_pos_x, save_base_pos_y * 3, "�Z�[�u�f�[�^3", 255);

		DxLib::DrawString(save_name_pos_x - cursor_move, save_base_pos_y * 4, "�߂�", 255);
	}

	//�Z�[�u/���[�h���j���[�L�[����
	void SaveLoadMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (save_buttom_y == cursor_y) ? save_base_pos_y : cursor_y + save_move_unit;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (save_base_pos_y == cursor_y) ? save_buttom_y : cursor_y - save_move_unit;

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//�Z�[�u�f�[�^���Z�[�u
	int SaveDataSave(const char* SaveDataPath, const char* Message) {

		if (IDYES == MessageBoxYesNo(Message)) {

			SaveData_t SaveData = { EndFlag, SP, 0, CharacterHandle, BackGroundHandle, BackGroundMusicHandle };

			FILE *fp;

			fopen_s(&fp, SaveDataPath, "wb");//�o�C�i���t�@�C�����J��
			if (nullptr == fp) {//�G���[���N������nullptr��Ԃ�
				return 0;
			}

			fwrite(&SaveData, sizeof(SaveData), 1, fp); // SaveData_t�\���̂̒��g���o��
			fclose(fp);

			MessageBoxOk("�Z�[�u���܂����I");
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
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

			EndFlag = SaveData.ENDFLAG;
			SP = SaveData.SP;
			CP = SaveData.CP;
			CharacterHandle = SaveData.CHAR;
			BackGroundHandle = SaveData.BG;
			BackGroundMusicHandle = SaveData.BGM;

			MessageBoxOk("���[�h���܂����I");
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}
		return 0;
	}

	//�Z�[�u�f�[�^���f���[�g
	int SaveDataDelete(const char* SaveDataPath, const char* Message) {
		if (IDYES == MessageBoxYesNo(Message)) {
			std::remove(SaveDataPath);

			MessageBoxOk("�폜���܂����I");
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
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
			SaveFlag = SaveDataSave(SaveDataPath, Message.c_str());

		//���[�h
		if (Num == 2)
			SaveFlag = SaveDataLoad(SaveDataPath, Message.c_str());

		//�f���[�g
		if (Num == 3)
			SaveFlag = SaveDataDelete(SaveDataPath, Message.c_str());
	}

	//�Z�[�u/���[�h/�f���[�g ���j���[�I������
	void SaveLoadDeleteMenuSelect(std::int32_t& cursor_y, const int& Num, std::int32_t& SaveFlag) {

		if (cursor_y == save_base_pos_y && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			SaveDataTask(Num, "DATA/SAVE/SAVEDATA1.bat", "�Z�[�u�f�[�^�P", SaveFlag);
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}


		if (cursor_y == save_base_pos_y * 2 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			SaveDataTask(Num, "DATA/SAVE/SAVEDATA2.bat", "�Z�[�u�f�[�^�Q", SaveFlag);
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}


		if (cursor_y == save_base_pos_y * 3 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			SaveDataTask(Num, "DATA/SAVE/SAVEDATA3.bat", "�Z�[�u�f�[�^�R", SaveFlag);
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}


		if (cursor_y == save_base_pos_y * 4 && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {

			if (IDYES == MessageBoxYesNo("�߂�܂����H")){
				SaveFlag = 0;
				std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}
	}
}

//�Z�[�u�f�[�^(�Z�[�u/���[�h/�f���[�g)���[�v
void SaveDataLoop(const int& Num) {

	//�e�핪��\��
	if (IDYES == MessageBoxYesNo(SaveTaskItem[Num - 1])) {

		std::int32_t SaveFlag = 1;

		DxLib::ClearDrawScreen();
		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

		//�X�N���[���V���b�g�̓Ǎ�
		SaveDataSnapLoad();

		std::int32_t save_y = save_base_pos_y;

		while (SaveFlag == 1) {
			SaveLoadDeleteMenuDraw(save_y);
			SaveLoadMenuKeyMove(save_y);
			SaveLoadDeleteMenuSelect(save_y, Num, SaveFlag);
			ScreenClear();
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
}