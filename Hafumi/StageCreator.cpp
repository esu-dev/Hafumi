#include "StageCreator.h"

#include "GameEngine.h"
#include "StageBlock.h"

using namespace SceneManagement;

void StageCreator::Update()
{
	if (_creationTimer >= _creationInterval)
	{
		_creationTimer = 0;

		GameObject* stageBlock = new GameObject();
		stageBlock->AddComponent<SpriteRenderer>();
		stageBlock->AddComponent<BoxCollider2D>()->SetSize(Vector2(2, 2));
		stageBlock->AddComponent<Rigidbody2D>()->SetUseGravity(false);
		stageBlock->AddComponent<StageBlock>()->Initialize(1);
		stageBlock->GetTransform()->position = Vector3(_createdPosition, -5, 0);

		SceneManager::GetActiveScene()->AddGameObject(stageBlock);
		
		_createdPosition += 1.5;

		Debug::Log(L"create");
	}

	_creationTimer += Time::GetDelataTime();
}