#include "StageBlock.h"

#include "GameEngine.h"

void StageBlock::Update()
{
	if (!_willFall)
	{
		return;
	}

	if (_timer >= _fallTime)
	{
		// Ž©—R—Ž‰ºŠJŽn
		this->gameObject->GetComponent<Rigidbody2D>()->SetUseGravity(true);

		_timer = 0;
	}

	_timer += Time::GetDelataTime();
}

void StageBlock::SetFallTime(float fallTime)
{
	_willFall = true;
	_fallTime = fallTime;
}