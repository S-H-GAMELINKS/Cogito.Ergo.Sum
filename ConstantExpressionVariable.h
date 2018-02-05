#ifndef CONSTANT_EXPRESSION_VARIABLE_H_
#define CONSTANT_EXPRESSION_VARIABLE_H_

//�e��f�ލő吔
constexpr int MaterialMax = 99;

// �����̃T�C�Y
constexpr int MojiSize = 21;

//�^�C�g�����j���[�ʒu
constexpr int TitleMenuPosY = 300;
constexpr int TitleMenuPosX = 430;
constexpr int title_menu_load_y = 330;
constexpr int title_menu_config_y = 360;
constexpr int title_menu_quick_load_y = 390;
constexpr int title_menu_continue_y = 420;
constexpr int title_menu_exit_y = 450;

//�^�C�g�����j���[�̃J�[�\���ʒu
constexpr int TitleMenuCursorPosX = 400;

//�I����
constexpr int ChoicePosX = 100;
constexpr int ChoicePosY[] = { 200, 230 };

//�L�[�J�[�\���̈ړ���
constexpr int CursorMove = 30;

//�L�[������~����
constexpr int WaitKeyTaskTime = 70;

//�Q�[���v���C���̒x������
constexpr int WaitGameTime = 3;

//�Q�[�����j���[�ʒu�֌W
constexpr int GameMenuBasePosY = 30;

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
constexpr int string_speed_wait = 600;

//�����G�ʒu�֌W
constexpr int character_pos_y = 130;
constexpr int character_pos_x = 150;
constexpr int character_graph_size_x = 300;
constexpr int character_graph_size_y = 400;

#endif // CONSTANT_EXPRESSION_VARIABLE_H_