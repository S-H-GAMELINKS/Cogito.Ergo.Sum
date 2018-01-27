#ifndef CONSTANT_EXPRESSION_VARIABLE_H_
#define CONSTANT_EXPRESSION_VARIABLE_H_

//�e��f�ލő吔
constexpr int MaterialMax = 99;

// �����̃T�C�Y
constexpr int moji_size = 24;

//�^�C�g�����j���[�ʒu
constexpr int title_menu_y = 300;
constexpr int title_menu_x = 430;
constexpr int title_menu_load_y = 330;
constexpr int title_menu_config_y = 360;
constexpr int title_menu_quick_load_y = 390;
constexpr int title_menu_continue_y = 420;
constexpr int title_menu_exit_y = 450;

//�^�C�g�����j���[�̃J�[�\���ʒu
constexpr int title_menu_cursor_x = 400;

//�I����
constexpr int choice_pos_x = 100;
constexpr int choice_pos_y[] = { 200, 230 };

//�L�[�J�[�\���̈ړ���
constexpr int cursor_move = 30;

//�L�[������~����
constexpr int wait_key_task_time = 70;

//�Q�[���v���C���̒x������
constexpr int wait_game_time = 3;

//�Q�[�����j���[�ʒu�֌W
constexpr int game_menu_base_pos_y = 30;

//�Z�[�u�E���[�h��ʊ֌W
constexpr int save_max_num = 3;
constexpr int save_base_pos_x = 400;
constexpr int save_base_pos_y = 100;
constexpr int save_move_unit = 100;
constexpr int save_buttom_y = save_base_pos_y + save_move_unit * save_max_num;
constexpr int save_snap_draw_pos_x = 150;
constexpr int save_name_pos_x = 250;

//�����`�摬�x�֌W
constexpr int string_speed_skip = 10;
constexpr int string_speed_auto = 30;

#endif // CONSTANT_EXPRESSION_VARIABLE_H_