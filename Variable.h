// Variable Manage Source
#ifndef VALIABLE_H_
#define VALIABLE_H_

#include <vector>
#include <string>

// �����̃T�C�Y
extern const std::int32_t moji_size = 24;

int DrawPointX = 0, DrawPointY = 0;	// ������`��̈ʒu
int SP = 0, CP = 0;	// �Q�Ƃ��镶����ԍ��ƕ����񒆂̕����|�C���^

int EndFlag = 0;	// �I���t���O

					//�X�N���v�g�i�[�ϐ�
static std::vector<std::string> Script;

//�w�i�摜�i�[�ϐ�
static std::vector<int> BackGround;

//�����G�i�[�ϐ�
static std::vector<int> Character;

//BGM�i�[�ϐ�
static std::vector<int> BackGroundMusic;

static std::vector<int> SoundEffect;

//����i�[�ϐ�
static std::vector<std::string> Movie;

#endif //VALIABLE_H_