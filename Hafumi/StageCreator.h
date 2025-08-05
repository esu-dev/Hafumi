#pragma once

#include "framework.h"

#include "Component.h"

class StageCreator : public Component
{
public:
	void Update() override;

	class ItemData
	{
		GameObject* item;
		float PosX;
	};

private:
	const float STANDARD_HEIGHT = -5;
	float _creationInterval = 1;
	float _creationTimer = 0;
	float _createdPosition = -10;

	float _itemCreationIntrval = 1;
	float _lastCreatedPosition = -10;

	std::vector<ItemData> _itemDataVector;
};

