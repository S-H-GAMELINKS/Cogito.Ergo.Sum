#ifndef MOUSE_AND_KEY_STATE_
#define MOUSE_AND_KEY_STATE_

#include <cstdint>

namespace KeyState {

	//�L�[���씻��̃e���v���[�g
	std::int32_t KeyMoveTemplate(std::int32_t CursorPosY, std::int32_t TopPosY, std::int32_t ButtomPosY, std::int32_t Move, std::int32_t Flag);
}

namespace MouseState {

	//�^�C�g�����j���[�̃}�E�X����
	std::int32_t GameTitleMenuMouseMove(std::int32_t CursorPosY) noexcept;

	//�R���t�B�O��ʃ}�E�X����
	std::int32_t ConfigMenuMouseMove(std::int32_t ConfigCursorPosY) noexcept;

	//�Q�[�����j���[�̃}�E�X����
	std::int32_t GameMenuMouseMove(std::int32_t GameMenuCursorPosY) noexcept;

	//�I�����}�E�X����
	std::int32_t ChoiceMouseMove(std::int32_t ChoiceCursorPosY) noexcept;

	//�Z�[�u�f�[�^���j���[�}�E�X����
	std::int32_t SaveDataMenuMouseMove(std::int32_t SaveDataMenuPosY) noexcept;
}

namespace MouseAndKey {

	//�}�E�X���L�[�m�F�i�E�j
	bool CheckMouseAndKeyRight();

	//�}�E�X���L�[�m�F�i���j
	bool CheckMouseAndKeyLeft();

	//�}�E�X���L�[�m�F�i����j
	bool CheckMouseAndKeyEnter();
}

#endif // !MOUSE_AND_KEY_STATE_