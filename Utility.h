#ifndef UTILITY_H_
#define UTILITY_H_

//���b�Z�[�W�{�b�N�X(Yes or No)
int MessageBoxYesNo(LPCTSTR lpText) noexcept;

//���b�Z�[�W�{�b�N�X(OK)
int MessageBoxOk(LPCTSTR lpText) noexcept;

//��ʃN���A�����֐�
void ScreenClear() noexcept;

//�Q�[���I���m�F�E�C���h�E
void GameEndMessageBox();

//�e��V���[�g�J�b�g�L�[
void ShortCutKey();

//�^�C�g�����[�r�[����
void TitleMoviePlay();

#endif // !UTILITY_H_
