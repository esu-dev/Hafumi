#pragma once

#include "framework.h"

#include "Component.h"
#include "StageBlock.h"

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

	// �u���b�N
	float _creationInterval = 0.6f;
	float _creationTimer = 0;
	float _createdPosition = -10;

	float _fallInterval = 3;
	float _fallTimer = 0;

	std::vector<StageBlock*> _blockVector;


	// �A�C�e��
	float _itemCreationIntrval = 2;
	float _itemCreationTimer = 0;
	float _lastCreatedPosition = -5.5;

	std::vector<ItemData*> _itemDataVector;
};

