#include "Character.h"

#include "GameEngine.h"

// public
void Character::Update()
{
	state->Update();
}

void Character::Initialize(GameObject* stone1, GameObject* stone2)
{
	this->stone1 = stone1;
	this->stone2 = stone2;
	this->fulcrumStone = stone1;
	this->movingStone = stone2;
}

void Character::Rotate()
{
	state = rotationState;
}

void Character::IncreaseStickNum()
{
	stickNum++;
	SetStonePosition();
}

void Character::DecreaseStickNum()
{
	stickNum--;
	if (stickNum < 1)
	{
		stickNum = 1;
	}
	SetStonePosition();
}


// private
void Character::SetStonePosition()
{
	Vector3 relatedVector = movingStone->GetTransform()->position - fulcrumStone->GetTransform()->position;
	movingStone->GetTransform()->position = fulcrumStone->GetTransform()->position + relatedVector.GetNormalized() * stickNum * 1;
}


// State
Character::State::State(Character* character)
{
	this->character = character;
}


// StandardState
Character::StandardState::StandardState(Character* character) : Character::State(character) {}

void Character::StandardState::Update()
{
	//Debug::Log(L"update");
}


// RotationState
Character::RotationState::RotationState(Character* character) : Character::State(character) {}

void Character::RotationState::Update()
{
	// 支点石からの相対ベクトルを求める
	Vector3 relatedVector = GetCharacter()->movingStone->GetTransform()->position - GetCharacter()->fulcrumStone->GetTransform()->position;

	GetCharacter()->movingStone->GetTransform()->position = GetCharacter()->fulcrumStone->GetTransform()->position + Quaternion::AngleAxis(-45 * Time::GetDelataTime(), Vector3::forward).Mult(relatedVector);
}

