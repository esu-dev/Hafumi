#include "SampleSceneAsset.h"

#include "GameEngine.h"

#include "Character.h"
#include "StageCreator.h"

using namespace SceneManagement;

void SampleSceneAsset::load_scene_asset_impl()
{
	Scene* scene = SceneManager::CreateScene("SampleSceneAsset");

	GameObject* camera = new GameObject();
	camera->AddComponent<Camera>();

	GameObject* stageCreatorObject = new GameObject();
	stageCreatorObject->AddComponent<StageCreator>();

	scene->AddGameObject(stageCreatorObject);

	GameObject* stone1 = new GameObject();
	stone1->AddComponent<SpriteRenderer>();

	GameObject* stone2 = new GameObject();
	stone2->AddComponent<SpriteRenderer>();
	stone2->GetTransform()->position = Vector3(-3, 0, 0);

	GameObject* characterObject = new GameObject();
	Character* character = characterObject->AddComponent<Character>();
	character->Initialize(stone1, stone2);


	scene->AddGameObject(stone1);
	scene->AddGameObject(stone2);
	scene->AddGameObject(characterObject);

	SceneManager::SetActiveScene(scene);
}