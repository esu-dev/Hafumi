#include "InputReceiver.h"

#include "GameEngine.h"
#include "Character.h"

void InputReceiver::Update()
{
	if (Input::GetKeyDown(VK_SPACE))
	{
		character->Rotate();
	}

	if (Input::GetKeyDown('S'))
	{
		character->DecreaseStickNum();
	}
	else if (Input::GetKeyDown('W'))
	{
		character->IncreaseStickNum();
	}
}

void InputReceiver::Initialize(Character* character)
{
	this->character = character;
}
