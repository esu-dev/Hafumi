#pragma once

#include "SceneAsset.h"
#include "Scene.h"

using namespace SceneManagement;

class SampleSceneAsset : public SceneAsset<SampleSceneAsset>
{
public:
	static Scene* load_scene_asset_impl();
};