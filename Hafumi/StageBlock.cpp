#include "StageBlock.h"

#include "GameEngine.h"

void StageBlock::Update()
{
	if (_timer >= _fallTime)
	{
		// ���R�����J�n
		this->gameObject->GetComponent<Rigidbody2D>()->SetUseGravity(true);

		_timer = 0;
	}

	_timer += Time::GetDelataTime();
}

void StageBlock::Initialize(float fallTime)
{
	_fallTime = fallTime;
}