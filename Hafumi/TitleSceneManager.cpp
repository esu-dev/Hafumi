#include "TitleSceneManager.h"

#include "framework.h"
#include "GameEngine.h"
#include "SampleSceneAsset.h"

using namespace SceneManagement;

void TitleSceneManager::Update()
{
	if (Input::GetKeyDown(VK_SPACE))
	{
		/*std::string s = SceneManager::GetActiveScene()->GetName();
		std::wstring ws(s.begin(), s.end());
		Debug::Log(L"string %s", ws.c_str());*/

		Scene* scene = SampleSceneAsset::load();
		SceneManager::LoadScene("SampleSceneAsset");
	}
}