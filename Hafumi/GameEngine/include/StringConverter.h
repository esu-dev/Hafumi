#pragma once

#include "framework.h"

class StringConverter
{
public:
	static LPWSTR stringToLPWSTR(std::string str)
	{
		setlocale(LC_CTYPE, "jpn"); // �n��ݒ����{��ɐݒ�B���{��̓}���`�o�C�g�����ł��邩��ϊ�����K�v������B
		wchar_t wide[256]; // wchar_t�̓��C�h�����i���j�R�[�h�j��\�����߂̃f�[�^�^
		size_t ret; // size_t �̓I�u�W�F�N�g�̃o�C�g����\���ł�����x�ɏ\���ɑ傫�������Ȃ������^�B
		mbstowcs_s(&ret, wide, str.c_str(), 256);
		return wide;
	}
};