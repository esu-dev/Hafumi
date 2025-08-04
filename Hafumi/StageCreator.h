#pragma once

#include "Component.h"

class StageCreator : public Component
{
public:
	void Update() override;

private:
	float _creationInterval = 1;
	float _creationTimer = 0;
	float _createdPosition = -10;
};

