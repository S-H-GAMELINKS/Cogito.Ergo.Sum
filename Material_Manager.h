#ifndef MATERIAL_MANAGER_CPP_
#define MATERIAL_MANAGER_CPP_

#include <vector>
#include <string>

//�e��f�ޓǍ��֐�
void MaterialLoad(std::vector<int>& BackGround, std::vector<int>& Character, std::vector<int>& BackGroundMusic, std::vector<int>& SoundEffect, std::vector<std::string>& Movie);

//�X�N���v�g�Ǎ��֐�
void ScriptRead(std::vector<std::string>& Script, unsigned int EndFlag);

#endif // MATERIAL_MANAGER_CPP_