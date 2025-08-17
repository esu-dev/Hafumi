#pragma once

#include "MonoBehaviour.h"

class FPS_Shower : public MonoBehaviour
{
public:
	void Update() override;

private:
	const int countNum = 10;
	float _time = 0;
	float _frameNum = 0;
};

