#include "StageCreator.h"

#include "framework.h"

#include "GameEngine.h"

using namespace SceneManagement;


StageCreator* StageCreator::Instance = nullptr;

void StageCreator::Update()
{
	// ブロックの生成
	if (_creationTimer >= _creationInterval)
	{
		_creationTimer = 0;


		GameObject* stageBlock = new GameObject();
		stageBlock->AddComponent<SpriteRenderer>();
		stageBlock->AddComponent<BoxCollider2D>()->SetSize(Vector2(1.5, 1.5));
		stageBlock->AddComponent<Rigidbody2D>()->SetUseGravity(false);
		StageBlock* stageBlockScript = stageBlock->AddComponent<StageBlock>();
		stageBlock->GetTransform()->position = Vector3(_createdPosition, STANDARD_HEIGHT, 0);

		_blockVector.push_back(stageBlockScript);

		SceneManager::GetActiveScene()->AddGameObject(stageBlock);

		_createdPosition += 1.5;
	}

	// ブロックの落下
	if (_fallTimer >= _fallInterval)
	{
		_fallTimer = 0;

		_blockVector[0]->SetFallTime(0.5f);
		_blockVector.erase(_blockVector.begin());
	}

	// アイテムの生成
	if (_itemCreationTimer >= _itemCreationIntrval)
	{
		_itemCreationTimer = 0;

		float createdPositionX = _lastCreatedPosition + (rand() % 10 + 1) * 1.5f;
		GameObject* item = new GameObject();
		item->AddComponent<SpriteRenderer>()->SetColor(DirectX::XMFLOAT4(0, 1, 0, 1));
		item->GetTransform()->position = Vector3(createdPositionX, STANDARD_HEIGHT + 1, 0);
		item->GetTransform()->scale = Vector3(0.5f, 0.5f, 0);

		SceneManager::GetActiveScene()->AddGameObject(item);

		ItemData* itemData = new ItemData();
		itemData->item = item;
		itemData->PosX = createdPositionX;
		_itemDataVector.push_back(itemData);

		_lastCreatedPosition = createdPositionX;
	}


	_creationTimer += Time::GetDelataTime();
	_fallTimer += Time::GetDelataTime();
	_itemCreationTimer += Time::GetDelataTime();
}

StageCreator::StageCreator()
{
	if (Instance == nullptr)
	{
		Instance = this;
	}
}

bool StageCreator::GetItem(float posX)
{
	ItemData* itemData = std_extension::Find<ItemData*>(_itemDataVector, [&](ItemData* x) -> bool { return abs(x->PosX - posX) < 0.1f; });

	//_itemDataVector.erase(std::remove(_itemDataVector.begin(), _itemDataVector.end(), itemData), _itemDataVector.end());
	std_extension::Remove(_itemDataVector, itemData);

	if (itemData)
	{
		Destroy(itemData->item);
		delete itemData;

		return true;
	}

	return false;
}