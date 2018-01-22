// Variable Manage Source
#ifndef VALIABLE_H_
#define VALIABLE_H_

#include <vector>
#include <string>
#include <array>

//�Q�[���^�C�g��
extern const char* GameTitle = "�m�x���Q�[���G���W���uLINKS�v for C++";

// �����̃T�C�Y
extern const std::int32_t moji_size = 24;

int DrawPointX = 0, DrawPointY = 0;	// ������`��̈ʒu
int SP = 0, CP = 0;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

int EndFlag = 0;	// �I���t���O

//�X�N���v�g�i�[�ϐ�
static std::vector<std::string> Script;

//�w�i�摜�i�[�ϐ�
std::array<int, 99> BackGround;

//�����G�i�[�ϐ�
static std::array<int, 99> Character;

//BGM�i�[�ϐ�
static std::array<int, 99> BackGroundMusic;

static std::array<int, 99> SoundEffect;

//����i�[�ϐ�
static std::array<std::string, 99> Movie;

#endif //VALIABLE_H_