#pragma once

#include "framework.h"

class Event
{
public:
	// �Ȃ���.cpp�Ŏ����ł��Ȃ���������.h�Ŏ���
	void AddListener(std::function<void(void)> func);
	void Invoke();
	void RemoveAllListener();

private:
	std::vector<std::function<void(void)>> _functionVector;
};