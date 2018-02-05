#ifndef MATERIAL_MANAGER_CPP_
#define MATERIAL_MANAGER_CPP_

#include "ConstantExpressionVariable.h"
#include <vector>
#include <string>
#include <array>

//�e��f�ޓǍ��֐�
void MaterialLoad(std::array<int, MaterialMax>& BackGround, std::array<int, MaterialMax>& Character, std::array<int, MaterialMax>& BackGroundMusic, std::array<int, MaterialMax>& SoundEffect, std::array<std::string, MaterialMax>& Movie, std::int32_t& GameTitleGraph) noexcept;

//�X�N���v�g�Ǎ��֐�
void ScriptRead(std::vector<std::string>& Script, unsigned int EndFlag) noexcept;

#endif // MATERIAL_MANAGER_CPP_