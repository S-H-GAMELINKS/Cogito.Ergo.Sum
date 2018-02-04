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

	//�e��f�ޓǍ��e���v���[�g�֐�
	template <typename T>
	void MaterialLoadTemplate(std::array<T, MaterialMax>& Material, const std::string& FilePath, const std::string& FileFormat) {
		for (std::int32_t i = 0; i < MaterialMax; i++) {

			if (CheckMaterialExistence(MaterialPathCalc(i, FilePath, FileFormat)))
				Material[i] = DxLib::LoadGraph(MaterialPathCalc(i, FilePath, FileFormat).c_str());
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
	MaterialLoadTemplate(BackGround, "DATA/BACKGROUND/BG", ".png");

	//�����G�摜�Ǎ��֐�
	MaterialLoadTemplate(Character, "DATA/BACKGROUND/CHAR", ".png");

	//BGM�Ǎ��֐�
	MaterialLoadTemplate(BackGroundMusic, "DATA/BACKGROUND/BGM", ".png");

	//SE�Ǎ��֐�
	MaterialLoadTemplate(SoundEffect, "DATA/BACKGROUND/SE", ".png");

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
