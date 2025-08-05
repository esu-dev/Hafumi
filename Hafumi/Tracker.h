#pragma once

#include "MonoBehaviour.h"
#include "Vector3.h"

class Tracker : public MonoBehaviour
{
public:
	void Update() override;

	void SetMovingRate(float movingRate) { _movingRate = movingRate; }
	void SetOffset(Vector3 offset) { _offset = offset; };
	void SetTarget(GameObject* target) { _target = target; }

private:
	float _movingRate = 0.01f;
	Vector3 _offset = Vector3(0, 0, 0);
	GameObject* _target;
};

