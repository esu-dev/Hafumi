#include "SampleSceneAsset.h"

#include "GameEngine.h"

#include "Character.h"
#include "StageCreator.h"
#include "InputReceiver.h"
#include "Tracker.h"

using namespace SceneManagement;

Scene* SampleSceneAsset::load_scene_asset_impl()
{
	Scene* scene = SceneManager::CreateScene("SampleSceneAsset");

	GameObject* camera = new GameObject();
	camera->AddComponent<Camera>();
	camera->AddComponent<Tracker>();

	GameObject* stageCreatorObject = new GameObject();
	stageCreatorObject->AddComponent<StageCreator>();


	GameObject* stone1 = new GameObject();
	stone1->AddComponent<SpriteRenderer>()->SetColor(DirectX::XMFLOAT4(1, 0, 0, 1));

	GameObject* stone2 = new GameObject();
	stone2->AddComponent<SpriteRenderer>();
	stone2->GetTransform()->position = Vector3(-3, 0, 0);

	GameObject* characterObject = new GameObject();
	Character* character = characterObject->AddComponent<Character>();
	character->Initialize(stone1, stone2);


	GameObject* inputReceiverObject = new GameObject();
	InputReceiver* inputReceiver = inputReceiverObject->AddComponent<InputReceiver>();
	inputReceiver->Initialize(character);


	GameObject* testObject = new GameObject();
	testObject->AddComponent<SpriteRenderer>();
	testObject->AddComponent<BoxCollider2D>();
	testObject->AddComponent<Rigidbody2D>();
	testObject->GetTransform()->position = Vector3(5, 0, 0);

	// scene->AddGameObject(testObject);


	scene->AddGameObject(camera);
	scene->AddGameObject(inputReceiverObject);
	scene->AddGameObject(stageCreatorObject);
	scene->AddGameObject(stone1);
	scene->AddGameObject(stone2);
	scene->AddGameObject(characterObject);

	SceneManager::SetActiveScene(scene);
	SceneManager::GetActiveScene()->AddGameObject(testObject);

	return scene;
}