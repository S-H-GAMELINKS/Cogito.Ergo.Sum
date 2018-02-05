#ifndef CONSTANT_EXPRESSION_VARIABLE_H_
#define CONSTANT_EXPRESSION_VARIABLE_H_

//�e��f�ލő吔
constexpr int MaterialMax = 99;

// �����̃T�C�Y
constexpr int MojiSize = 21;

//�^�C�g�����j���[�ʒu
constexpr int TitleMenuPosY = 300;
constexpr int TitleMenuPosX = 430;
constexpr int TitleMenuLoadPosY = 330;
constexpr int TitleMenuConfigPosY = 360;
constexpr int TitleMenuQuickLoadPosY = 390;
constexpr int TitleMenuContinuePosY = 420;
constexpr int TitleMenuExitPosY = 450;

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
constexpr int StringSpeedSkip = 10;
constexpr int StringSpeedAuto = 30;
constexpr int StringSpeedWait = 600;

//�����G�ʒu�֌W
constexpr int CharacterPosY = 130;
constexpr int CharacterPosX = 150;
constexpr int character_graph_size_x = 300;
constexpr int character_graph_size_y = 400;

#endif // CONSTANT_EXPRESSION_VARIABLE_H_