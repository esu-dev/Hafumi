#pragma once

#include "MonoBehaviour.h"

class StageBlock : public MonoBehaviour
{
public:
	void Update() override;

	void Initialize(float fallTime);

private:
	float _fallTime;
	float _timer = 0;
};

