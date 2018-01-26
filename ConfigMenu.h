#ifndef CONFIG_MENU_H_
#define CONFIG_MENU_H_

#include <cstdint>

//�R���t�B�O��ʃ��[�v
void ConfigMenuLoop();

//�R���t�B�O�Ǎ��֐�
int ConfigLoad();

//�R���t�B�O�ۑ��֐�
int ConfigSave();

//�ݒ�f�[�^
struct alignas(4) ConfigData_t {
	std::int32_t bgm_vol;				//BGM���ʏ��
	std::int32_t bgm_vol_count;			//BGM���ʃ��[�^�[���
	std::int32_t se_vol;					//SE���ʏ��
	std::int32_t se_vol_count;			//SE���ʃ��[�^�[���
	std::int32_t skip_speed;				//�X�L�b�v���x���
	std::int32_t skip_speed_count;		//�X�L�b�v���x���[�^�[���
	std::int32_t auto_speed;				//�I�[�g���x���
	std::int32_t auto_speed_count;		//�I�[�g���x���[�^�[���
	std::int32_t string_speed;			//������`�摬�x
	std::int32_t string_speed_count;		//������`�摬�x���[�^�[���
	std::int32_t mouse_key_move;			//�}�E�X����ƃL�[����̏�� true/false
};

#endif // !CONFIG_MENU_H_
