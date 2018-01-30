#ifndef SAVEDATA_H_
#define SAVEDATA_H_

#include <cstdint>

//�Z�[�u�f�[�^(�Z�[�u/���[�h/�f���[�g)���[�v
void SaveDataLoop(const int& Num);

//�Z�[�u�f�[�^���Z�[�u(Quick)
int QuickSaveDataSave();

//�Z�[�u�f�[�^�����[�h(Quick)
int QuickSaveDataLoad();

//�Z�[�u�f�[�^���Z�[�u(Continue)
int ContinueSaveDataSave(const std::int32_t& RouteNum);

//�Z�[�u�f�[�^�����[�h(Continue)
int ContinueSaveDataLoad();

//�Z�[�u�f�[�^�p�X�N���[���V���b�g�擾
void SaveDataScreenShotGet();

#endif // SAVEDATA_H_