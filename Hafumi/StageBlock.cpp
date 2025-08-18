#include "StageBlock.h"

#include "GameEngine.h"

void StageBlock::Update()
{
	if (!_willFall)
	{
		return;
	}

	if (this->get_transform()->position.y < -15)
	{
		Destroy(this->gameObject);
		return;
	}

	if (_timer >= _fallTime)
	{
		// Ž©—R—Ž‰ºŠJŽn
		Rigidbody2D* rigidbody = this->gameObject->GetComponent<Rigidbody2D>();
		this->gameObject->GetComponent<BoxCollider2D>()->Getb2Body()->SetType(b2BodyType::b2_dynamicBody);

		_timer = 0;
	}

	_timer += Time::GetDelataTime();
}

void StageBlock::SetFallTime(float fallTime)
{
	_willFall = true;
	_fallTime = fallTime;
}