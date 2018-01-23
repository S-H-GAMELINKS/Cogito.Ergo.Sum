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

int EndFlag = -1;	// �I���t���O

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

std::int32_t GameTitleGraph;

//�^�C�g�����j���[�ʒu
extern const std::int32_t title_menu_y = 300;
extern const std::int32_t title_menu_x = 430;
extern const std::int32_t title_menu_load_y = 330;
extern const std::int32_t title_menu_config_y = 360;
extern const std::int32_t title_menu_quick_load_y = 390;
extern const std::int32_t title_menu_continue_y = 420;
extern const std::int32_t title_menu_exit_y = 450;

//�^�C�g�����j���[�̃J�[�\���ʒu
extern const std::int32_t title_menu_cursor_x = 400;

//�L�[�J�[�\���̈ړ���
extern const std::int32_t cursor_move = 30;

//������~����
extern const std::int32_t wait_task_time = 70;

#endif //VALIABLE_H_