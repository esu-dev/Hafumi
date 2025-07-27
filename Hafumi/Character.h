#pragma once

#include "GameObject.h"
#include "Component.h"

class Character : public Component
{
public:
	void Update() override;

	void Initialize(GameObject* stone1, GameObject* stone2);

private:
	int stickNum = 2;
	GameObject* stone1;
	GameObject* stone2;
	GameObject* fulcrumStone;

	class State
	{
	public:
		virtual void Update() {}
	};

	class StandardState : public State
	{
	public:
		void Update() override;
	};

	State* state = new StandardState();
};

