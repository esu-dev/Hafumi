#pragma once

#include "SceneAsset.h"

class SampleSceneAsset : public SceneAsset<SampleSceneAsset>
{
public:
	static void load_scene_asset_impl();
};