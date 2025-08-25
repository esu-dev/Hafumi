#include "Tracker.h"

#include "GameEngine.h"

void Tracker::Update()
{
	if (_target == nullptr)
	{
		return;
	}

	Vector3 distance = _target->GetTransform()->position - this->get_transform()->position + _offset;
	this->get_transform()->position = this->get_transform()->position + distance * _movingRate;
}

void Tracker::SetMovingRate(float movingRate) { _movingRate = movingRate; }
void Tracker::SetOffset(Vector3 offset) { _offset = offset; }
void Tracker::SetTarget(GameObject* target) { _target = target; }