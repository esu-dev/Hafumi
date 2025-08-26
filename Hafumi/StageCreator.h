#pragma once

#include "framework.h"

#include "Component.h"
#include "StageBlock.h"
#include "Character.h"

class StageCreator : public Component
{
public:
	static StageCreator* Instance;

	void Start() override;
	void Update() override;

	class ItemData
	{
	public:
		GameObject* item;
		float PosX;
	};

	StageCreator();
	void Initialize(Character* character);
	bool GetItem(float posX);


private:
	const float STANDARD_HEIGHT = -5;

	// ブロック
	float _creationInterval = 0.5f;
	float _creationTimer = 0;
	float _createdPosition = -10;

	float _fallInterval = 2.5f;
	float _fallTimer = 0;

	std::vector<StageBlock*> _blockVector;


	// アイテム
	float _itemCreationIntrval = 1;
	float _itemCreationTimer = 0;
	float _lastCreatedPosition = -5.5;

	std::vector<ItemData*> _itemDataVector;


	Character* _character;

	void CreateBlock();
};

