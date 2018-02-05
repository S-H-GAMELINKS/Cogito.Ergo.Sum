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
	bool CheckMaterialExistence(const std::string& FilePath) noexcept {
		std::ifstream Material(FilePath, std::ios_base::in);
		return Material.is_open();
	}

	//�e��f�ރt�@�C���p�X����
	std::string MaterialPathCalc(const std::int32_t& i, const std::string& FilePath, const std::string& FileFormat) noexcept {
		std::ostringstream Num;

		Num << std::setfill('0') << std::setw(2) << i + 1;

		return (FilePath + Num.str() + FileFormat);
	}

	//�e��f�ޓǍ��e���v���[�g�֐�
	template <typename T, typename Func>
	void MaterialLoadTemplate(std::array<T, MaterialMax>& Material, const std::string& FilePath, const std::string& FileFormat, Func&& loader) noexcept {
		for (std::int32_t i = 0; i < MaterialMax; i++) {
			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				Material[i] = loader(MaterialPathCalc(i, FilePath, FileFormat));
		}
	}
}

//�e��f�ޓǍ��֐�
void MaterialLoad(std::array<int, MaterialMax>& BackGround, std::array<int, MaterialMax>& Character, std::array<int, MaterialMax>& BackGroundMusic, std::array<int, MaterialMax>& SoundEffect, std::array<std::string, MaterialMax>& Movie, std::int32_t& GameTitleGraph) noexcept {

	//�T�E���h�f�[�^�̓ǂݍ��݌`��
	DxLib::SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMPRESS);

	//�w�i�摜�Ǎ��֐�
	MaterialLoadTemplate(BackGround, "DATA/BACKGROUND/BG", ".png", [](const std::string& path) {return DxLib::LoadGraph(path.c_str()); });

	//�����G�摜�Ǎ��֐�
	MaterialLoadTemplate(Character, "DATA/CHARACTER/CHAR", ".png", [](const std::string& path) {return DxLib::LoadGraph(path.c_str()); });

	//BGM�Ǎ��֐�
	MaterialLoadTemplate(BackGroundMusic, "DATA/BACKGROUNDMUSIC/BGM", ".ogg", [](const std::string& path) {return DxLib::LoadSoundMem(path.c_str());});

	//SE�Ǎ��֐�
	MaterialLoadTemplate(SoundEffect, "DATA/SOUNDEFFECT/SE", ".ogg", [](const std::string& path) {return DxLib::LoadSoundMem(path.c_str()); });

	//����Ǎ��֐�
	MaterialLoadTemplate(Movie, "DATA/MOVIE/MOVIE", ".wmv", [](const std::string& path) {return std::move(path); });

	//�^�C�g����ʓǍ�
	GameTitleGraph = DxLib::LoadGraph("DATA/BACKGROUND/TITLE.png");
}

//�X�N���v�g�Ǎ��֐�
void ScriptRead(std::vector<std::string>& Script, unsigned int EndFlag) noexcept {

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
