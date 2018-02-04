//Material Manage Source
#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace {

	//�e��f�ރt�@�C���m�F�֐�
	bool CheckMaterialExistence(const std::string& FilePath) {
		std::ifstream Material(FilePath, std::ios_base::in);
		return Material.is_open();
	}

	//�e��f�ރt�@�C���p�X����
	decltype(auto) MaterialPathCalc(const std::int32_t& i, const std::string& FilePath, const std::string& FileFormat) {
		std::ostringstream Num;

		Num << std::setfill('0') << std::setw(2) << i + 1;

		return (FilePath + Num.str() + FileFormat);
	}

	//�w�i�摜�Ǎ��֐�
	void MaterialLoadBackGround(std::array<int, MaterialMax>& BackGround) {

		const std::string FilePath = "DATA/BACKGROUND/BG";
		const std::string FileFormat = ".png";

		for (std::int32_t i = 0; i < MaterialMax; i++) {

			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				BackGround[i] = DxLib::LoadGraph(MaterialPathCalc(i, FilePath, FileFormat).c_str());
		}
	}

	//�����G�f�ޓǍ��֐�
	void MaterialLoadCharacter(std::array<int, MaterialMax>& Character) {

		const std::string FilePath = "DATA/CHARACTER/CHAR";
		const std::string FileFormat = ".png";

		for (std::int32_t i = 0; i < MaterialMax; i++) {

			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				Character[i] = DxLib::LoadGraph(MaterialPathCalc(i, FilePath, FileFormat).c_str());
		}
	}

	//BGM�Ǎ��֐�
	void MaterialLoadBackGroundMusic(std::array<int, MaterialMax>& BackGroundMusic) {

		const std::string FilePath = "DATA/BACKGROUNDMUSIC/BGM";
		const std::string FileFormat = ".ogg";

		for (std::int32_t i = 0; i < MaterialMax; i++) {

			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				BackGroundMusic[i] = DxLib::LoadSoundMem(MaterialPathCalc(i, FilePath, FileFormat).c_str());
		}
	}

	//SE�Ǎ��֐�
	void MaterialLoadSoundEffect(std::array<int, MaterialMax>& SoundEffect) {

		const std::string FilePath = "DATA/SOUNDEFFECT/SE";
		const std::string FileFormat = ".ogg";

		for (std::int32_t i = 0; i < MaterialMax; i++) {

			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				SoundEffect[i] = DxLib::LoadSoundMem(MaterialPathCalc(i, FilePath, FileFormat).c_str());
		}
	}

	//����Ǎ��֐�
	template <typename T>
	void MaterialLoadMovie(std::array<T, MaterialMax>& Movie) {

		const std::string FilePath = "DATA/MOVIE/MOVIE";
		const std::string FileFormat = ".wmv";

		for (std::int32_t i = 0; i < MaterialMax; i++) {

			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				Movie[i] = MaterialPathCalc(i, FilePath, FileFormat);
		}
	}
}

//�e��f�ޓǍ��֐�
void MaterialLoad(std::array<int, MaterialMax>& BackGround, std::array<int, MaterialMax>& Character, std::array<int, MaterialMax>& BackGroundMusic, std::array<int, MaterialMax>& SoundEffect, std::array<std::string, MaterialMax>& Movie, std::int32_t& GameTitleGraph) {

	//�T�E���h�f�[�^�̓ǂݍ��݌`��
	DxLib::SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMPRESS);

	//�w�i�摜�Ǎ��֐�
	MaterialLoadBackGround(BackGround);

	//�����G�摜�Ǎ��֐�
	MaterialLoadCharacter(Character);

	//BGM�Ǎ��֐�
	MaterialLoadBackGroundMusic(BackGroundMusic);

	//SE�Ǎ��֐�
	MaterialLoadSoundEffect(SoundEffect);

	//����Ǎ��֐�
	MaterialLoadMovie(Movie);

	//�^�C�g����ʓǍ�
	GameTitleGraph = DxLib::LoadGraph("DATA/BACKGROUND/TITLE.png");
}

//�X�N���v�g�Ǎ��֐�
void ScriptRead(std::vector<std::string>& Script, unsigned int EndFlag) {

	Script.clear();

	const char* ScriptFilePath[] = {
		"DATA/STR/LINKS.txt",
		"DATA/STR/A.txt",
		"DATA/STR/B.txt",
		"DATA/STR/C.txt",
		"DATA/STR/D.txt",
		"DATA/STR/E.txt",
		"DATA/STR/F.txt",
		"DATA/STR/G.txt",
		"DATA/STR/H.txt",
		"DATA/STR/I.txt",
		"DATA/STR/J.txt",
		"DATA/STR/K.txt",
		"DATA/STR/L.txt",
		"DATA/STR/M.txt",
		"DATA/STR/N.txt"
	};

	if (1 <= EndFlag && EndFlag < 16) {
		std::fstream file(ScriptFilePath[EndFlag - 1], std::ios_base::in);

		for (std::string line; std::getline(file, line); ) if (!line.empty()) Script.emplace_back(std::move(line));
	}
}
