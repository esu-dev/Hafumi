#include "StageCreator.h"

#include "GameEngine.h"

using namespace SceneManagement;

void StageCreator::Update()
{
	if (_creationTimer >= _creationInterval)
	{
		_creationTimer = 0;

		GameObject* stageBlock = new GameObject();
		stageBlock->AddComponent<SpriteRenderer>();
		stageBlock->GetTransform()->position = Vector3(_createdPosition, -5, 0);

		SceneManager::GetActiveScene()->AddGameObject(stageBlock);
		
		_createdPosition += 1.5;

		Debug::Log(L"create");
	}

	_creationTimer += Time::GetDelataTime();

	Debug::Log(L"update");
}