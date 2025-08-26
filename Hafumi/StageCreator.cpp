#include "StageCreator.h"

#include "framework.h"

#include "GameEngine.h"

using namespace SceneManagement;


StageCreator* StageCreator::Instance = nullptr;


void StageCreator::Start()
{
	for (int i = 0; i < 5; i++)
	{
		CreateBlock();
	}
}

void StageCreator::Update()
{
	// ブロックの生成
	if (_creationTimer >= _creationInterval)
	{
		if (_createdPosition - _character->GetFulcrumStone()->GetTransform()->position.x <= 30)
		{
			_creationTimer = 0;
			_creationInterval -= 0.01f;
			if (_creationInterval < 0.1f)
			{
				_creationInterval = 0.1f;
			}

			CreateBlock();
		}
	}

	// ブロックの落下
	if (_fallTimer >= _fallInterval)
	{
		// 残りのブロックの数が少ないなら落とさない
		if (_blockVector.size() >= 1)
		{
			_fallTimer = 0;
			_fallInterval -= 0.05f;
			if (_fallInterval < 0.25f)
			{
				_fallInterval = 0.25f;
			}

			_blockVector[0]->SetFallTime(0.1f);
			_blockVector.erase(_blockVector.begin());
		}
	}

	// アイテムの生成
	if (_itemCreationTimer >= _itemCreationIntrval)
	{
		if (_createdPosition - _character->GetFulcrumStone()->GetTransform()->position.x <= 30)
		{
			_itemCreationTimer = 0;
			_itemCreationIntrval -= 0.01f;
			if (_itemCreationIntrval < 0.01f)
			{
				_itemCreationIntrval = 0.01f;
			}

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

void StageCreator::Initialize(Character* character)
{
	_character = character;
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


// private
void StageCreator::CreateBlock()
{
	GameObject* stageBlock = new GameObject();
	stageBlock->AddComponent<SpriteRenderer>();
	BoxCollider2D* blockBoxCollider = stageBlock->AddComponent<BoxCollider2D>();
	blockBoxCollider->SetSize(Vector2(1.1, 1.1));
	Rigidbody2D* blockRigidbody = stageBlock->AddComponent<Rigidbody2D>();
	blockRigidbody->SetKinematic();
	StageBlock* stageBlockScript = stageBlock->AddComponent<StageBlock>();
	stageBlock->GetTransform()->position = Vector3(_createdPosition, STANDARD_HEIGHT, 0);

	_blockVector.push_back(stageBlockScript);

	SceneManager::GetActiveScene()->AddGameObject(stageBlock);

	_createdPosition += 1.5;
}