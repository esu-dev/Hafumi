#pragma once

#include "Component.h"

class Character;

class InputReceiver : public Component
{
public:
	void Update() override;

	Character* character;

	void Initialize(Character* character);
};