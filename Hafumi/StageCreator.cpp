#include "StageCreator.h"

#include "framework.h"

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
		stageBlock->AddComponent<StageBlock>()->Initialize(3);
		stageBlock->GetTransform()->position = Vector3(_createdPosition, STANDARD_HEIGHT, 0);

		SceneManager::GetActiveScene()->AddGameObject(stageBlock);

		_createdPosition += 1.5;


		float createdPositionX = _lastCreatedPosition + rand() % 5 * 1.5f;
		GameObject* item = new GameObject();
		item->AddComponent<SpriteRenderer>()->SetColor(DirectX::XMFLOAT4(0, 1, 0, 1));
		item->GetTransform()->position = Vector3(createdPositionX, STANDARD_HEIGHT + 1, 0);
		item->GetTransform()->scale = Vector3(0.5f, 0.5f, 0);

		SceneManager::GetActiveScene()->AddGameObject(item);

		_lastCreatedPosition = createdPositionX;

	}

	_creationTimer += Time::GetDelataTime();
}