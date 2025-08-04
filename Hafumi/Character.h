#pragma once

#include "GameObject.h"
#include "Component.h"

class Character : public Component
{
public:
	void Update() override;

	void Initialize(GameObject* stone1, GameObject* stone2);
	void Rotate();
	void IncreaseStickNum();
	void DecreaseStickNum();

private:
	int stickNum = 2;
	GameObject* stone1;
	GameObject* stone2;
	GameObject* fulcrumStone;
	GameObject* movingStone;

	class State
	{
	public:
		virtual void Update() {}

		Character* GetCharacter() { return character; }

		State(Character* character);

	private:
		Character* character;
	};

	class StandardState : public State
	{
	public:
		void Update() override;

		StandardState(Character* character);
	};

	class RotationState : public State
	{
	public:
		void Update() override;

		RotationState(Character* character);
	};

	StandardState* standardState = new StandardState(this);
	RotationState* rotationState = new RotationState(this);
	State* state = standardState;

	
	void SetStonePosition();
};

