#pragma once

#include "MonoBehaviour.h"

class StageBlock : public MonoBehaviour
{
public:
	void Update() override;

	void SetFallTime(float fallTime);

private:
	bool _willFall = false;
	float _fallTime = 0;
	float _timer = 0;
};

