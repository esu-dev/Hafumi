#include "Character.h"

#include "Debug.h"

void Character::Update()
{
	state->Update();
}

void Character::Initialize(GameObject* stone1, GameObject* stone2)
{
	this->stone1 = stone1;
	this->stone2 = stone2;
	this->fulcrumStone = stone1;
}

void Character::StandardState::Update()
{
	//Debug::Log(L"update");
}