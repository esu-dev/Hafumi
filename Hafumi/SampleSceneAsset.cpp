#include "SampleSceneAsset.h"

#include "GameEngine.h"

#include "Character.h"
#include "StageCreator.h"
#include "InputReceiver.h"
#include "Tracker.h"
#include "FPS_Shower.h"

using namespace SceneManagement;

Scene* SampleSceneAsset::load_scene_asset_impl()
{
	Scene* scene = SceneManager::CreateScene("SampleSceneAsset");

	GameObject* fpsText = new GameObject();
	fpsText->AddComponent<TextLabel>();
	fpsText->AddComponent<FPS_Shower>();
	fpsText->GetTransform()->SetPosition(-15, 10);
	scene->AddGameObject(fpsText);


	GameObject* camera = new GameObject();
	camera->tag = "MainCamera";
	camera->AddComponent<Camera>();
	camera->AddComponent<Tracker>();
	camera->GetTransform()->SetPosition(5, 0);
	scene->AddGameObject(camera);

	std::string s = SceneManager::GetActiveScene()->GetName();
	std::wstring ws(s.begin(), s.end());
	Debug::Log(L"string %s", ws.c_str());

	GameObject* stageCreatorObject = new GameObject();
	stageCreatorObject->AddComponent<StageCreator>();
	scene->AddGameObject(stageCreatorObject);


	GameObject* stone1 = new GameObject();
	stone1->AddComponent<SpriteRenderer>()->SetColor(DirectX::XMFLOAT4(1, 0, 0, 1));
	scene->AddGameObject(stone1);

	GameObject* stone2 = new GameObject();
	stone2->AddComponent<SpriteRenderer>();
	stone2->GetTransform()->position = Vector3(-3, 0, 0);
	scene->AddGameObject(stone2);

	GameObject* characterObject = new GameObject();
	Character* character = characterObject->AddComponent<Character>();
	character->Initialize(stone1, stone2);
	scene->AddGameObject(characterObject);


	GameObject* inputReceiverObject = new GameObject();
	InputReceiver* inputReceiver = inputReceiverObject->AddComponent<InputReceiver>();
	inputReceiver->Initialize(character);
	scene->AddGameObject(inputReceiverObject);


	GameObject* testObject = new GameObject();
	testObject->AddComponent<SpriteRenderer>();
	testObject->AddComponent<BoxCollider2D>();
	testObject->AddComponent<Rigidbody2D>();
	testObject->GetTransform()->position = Vector3(5, 0, 0);
	scene->AddGameObject(testObject);



	return scene;
}