#ifndef MATERIAL_MANAGER_CPP_
#define MATERIAL_MANAGER_CPP_

#include <vector>
#include <string>
#include <array>

//�e��f�ޓǍ��֐�
void MaterialLoad(std::array<int, 99>& BackGround, std::array<int, 99>& Character, std::array<int, 99>& BackGroundMusic, std::array<int, 99>& SoundEffect, std::array<std::string, 99>& Movie);

//�X�N���v�g�Ǎ��֐�
void ScriptRead(std::vector<std::string>& Script, unsigned int EndFlag);

#endif // MATERIAL_MANAGER_CPP_