#pragma once

#include "framework.h"

#include "Component.h"

class StageCreator : public Component
{
public:
	static StageCreator* Instance;

	void Update() override;

	class ItemData
	{
	public:
		GameObject* item;
		float PosX;
	};

	StageCreator();
	bool GetItem(float posX);


private:
	const float STANDARD_HEIGHT = -5;
	float _creationInterval = 1;
	float _creationTimer = 0;
	float _createdPosition = -10;

	float _itemCreationIntrval = 1;
	float _lastCreatedPosition = -5.5;

	std::vector<ItemData*> _itemDataVector;
};

