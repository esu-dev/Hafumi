#include "Character.h"

#include "GameEngine.h"
#include "Tracker.h"
#include "StageCreator.h"

// public
void Character::Start()
{
	Tracker* tracker = Camera::get_main()->gameObject->GetComponent<Tracker>();
	tracker->SetTarget(_fulcrumStone);
	tracker->SetOffset(-_fulcrumStone->GetTransform()->position);
}

void Character::Update()
{
	state->Update();

	//Debug::Log(L"delta time: %f", Time::GetDelataTime());
}

GameObject* Character::GetFulcrumStone()
{
	return _fulcrumStone;
}

void Character::Initialize(GameObject* stone1, GameObject* stone2)
{
	this->stone1 = stone1;
	this->stone2 = stone2;
	this->_fulcrumStone = stone1;
	this->_movingStone = stone2;

	_fulcrumStone->GetTransform()->position = Vector3(START_POS_X, STANDARD_HEIGHT, 0);
	_movingStone->GetTransform()->position = Vector3(START_POS_X - stickLengthUnit * stickNum, STANDARD_HEIGHT, 0);
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

	// 支点石からの相対ベクトルを求める
	Vector3 relatedVector = movingStone->GetTransform()->position - fulcrumStone->GetTransform()->position;

	movingStone->GetTransform()->position = fulcrumStone->GetTransform()->position + Quaternion::AngleAxis(-_angularSpeed * Time::GetDelataTime(), Vector3::forward).Mult(relatedVector);

	// 回転の終了
	if (movingStone->GetTransform()->position.y <= GetCharacter()->STANDARD_HEIGHT &&
		movingStone->GetTransform()->position.x > fulcrumStone->GetTransform()->position.x)
	{
		// 位置の調整
		movingStone->GetTransform()->position = Vector3(fulcrumStone->GetTransform()->position.x + GetCharacter()->stickNum * GetCharacter()->stickLengthUnit, GetCharacter()->STANDARD_HEIGHT, 0);

		// アイテム取得処理
		bool speedUp = StageCreator::Instance->GetItem(movingStone->GetTransform()->position.x);
		if (speedUp)
		{
			_angularSpeed += 5;

			Debug::Log(L"Speed Up");
		}

		// 支点石の変更
		GameObject* stone = fulcrumStone;
		GetCharacter()->_fulcrumStone = movingStone;
		GetCharacter()->_movingStone = stone;

		Camera::get_main()->gameObject->GetComponent<Tracker>()->SetTarget(GetCharacter()->_fulcrumStone);

		// 状態遷移
		if (GetCharacter()->_fulcrumStone == GetCharacter()->stone1)
		{
			//GetCharacter()->state = GetCharacter()->standardState;
		}
	}
}

