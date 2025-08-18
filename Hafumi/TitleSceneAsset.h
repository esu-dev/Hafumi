#pragma once

#include "SceneAsset.h"
#include "Scene.h"

using namespace SceneManagement;

class TitleSceneAsset : public SceneAsset<TitleSceneAsset>
{
public:
	static Scene* load_scene_asset_impl();
};