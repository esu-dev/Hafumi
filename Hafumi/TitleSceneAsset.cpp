#include "TitleSceneAsset.h"

#include "GameEngine.h"

using namespace SceneManagement;

Scene* TitleSceneAsset::load_scene_asset_impl()
{
	Scene* scene = SceneManager::CreateScene("SampleSceneAsset");
	
	GameObject* camera = new GameObject();
	camera->AddComponent<Camera>();
	scene->AddGameObject(camera);
	

	// ƒ^ƒCƒgƒ‹ƒƒS
	Texture* texture = new Texture("Resources/Texture/TitleLogo.png");
	GameObject* title = new GameObject();
	title->GetTransform()->SetPosition(0, 4);
	title->GetTransform()->scale = Vector3(1536 / 1024.0 * 10, 1024 / 1024.0 * 10, 0);
	title->AddComponent<SpriteRenderer>()->SetTexture(texture);
	scene->AddGameObject(title);


	// Press Any Key
	GameObject* text = new GameObject();
	text->GetTransform()->SetPosition(0, -5);
	text->AddComponent<TextLabel>()->SetText("Press Any Key");
	scene->AddGameObject(text);


	SceneManager::SetActiveScene(scene);

	return scene;
}