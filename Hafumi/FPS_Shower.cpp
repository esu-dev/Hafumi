#include "FPS_Shower.h"

#include "framework.h"
#include "GameEngine.h"

void FPS_Shower::Update()
{
	if (_frameNum >= countNum)
	{
		float fps = 1 / Time::GetDelataTime();
		this->get_gameObject()->GetComponent<TextLabel>()->SetText("fps: "s + std::to_string(fps));
		_frameNum = 0;
	}

	_frameNum += 1;
}