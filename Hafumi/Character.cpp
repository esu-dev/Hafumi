#include "Character.h"

#include "GameEngine.h"
#include "Tracker.h"

// public
void Character::Update()
{
	state->Update();

	//Debug::Log(L"delta time: %f", Time::GetDelataTime());
}

void Character::Initialize(GameObject* stone1, GameObject* stone2)
{
	this->stone1 = stone1;
	this->stone2 = stone2;
	this->_fulcrumStone = stone1;
	this->_movingStone = stone2;

	_fulcrumStone->GetTransform()->position = Vector3(START_POS_X, STANDARD_HEIGHT, 0);
	_movingStone->GetTransform()->position = Vector3(START_POS_X - stickLengthUnit * stickNum, STANDARD_HEIGHT, 0);

	Tracker* tracker = Camera::get_main()->gameObject->GetComponent<Tracker>();
	tracker->SetTarget(_fulcrumStone);
	tracker->SetOffset(-_fulcrumStone->GetTransform()->position);
}

void Character::Rotate()
{
	state = rotationState;
}

void Character::IncreaseStickNum()
{
	if (_fulcrumStone != stone1)
	{
		return;
	}

	stickNum++;
	SetStonePosition();
}

void Character::DecreaseStickNum()
{
	if (_fulcrumStone != stone1)
	{
		return;
	}

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
	Vector3 relatedVector = _movingStone->GetTransform()->position - _fulcrumStone->GetTransform()->position;
	_movingStone->GetTransform()->position = _fulcrumStone->GetTransform()->position + relatedVector.GetNormalized() * stickNum * stickLengthUnit;
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
	GameObject* fulcrumStone = GetCharacter()->_fulcrumStone;
	GameObject* movingStone = GetCharacter()->_movingStone;

	// Žx“_Î‚©‚ç‚Ì‘Š‘ÎƒxƒNƒgƒ‹‚ð‹‚ß‚é
	Vector3 relatedVector = movingStone->GetTransform()->position - fulcrumStone->GetTransform()->position;

	movingStone->GetTransform()->position = fulcrumStone->GetTransform()->position + Quaternion::AngleAxis(-45 * Time::GetDelataTime(), Vector3::forward).Mult(relatedVector);

	if (movingStone->GetTransform()->position.y <= GetCharacter()->STANDARD_HEIGHT &&
		movingStone->GetTransform()->position.x > fulcrumStone->GetTransform()->position.x)
	{
		movingStone->GetTransform()->position = Vector3(fulcrumStone->GetTransform()->position.x + GetCharacter()->stickNum * GetCharacter()->stickLengthUnit, GetCharacter()->STANDARD_HEIGHT, 0);

		// Žx“_Î‚Ì•ÏX
		GameObject* stone = fulcrumStone;
		GetCharacter()->_fulcrumStone = movingStone;
		GetCharacter()->_movingStone = stone;

		Camera::get_main()->gameObject->GetComponent<Tracker>()->SetTarget(GetCharacter()->_fulcrumStone);

		// ó‘Ô‘JˆÚ
		GetCharacter()->state = GetCharacter()->standardState;
	}
}

