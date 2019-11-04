#pragma once
#include "Scene.h"
#include "Director.h"
#include "GameScene.h"
#include "MousePointer.h"
class MainScene : public Scene
{
public:

	void Init() override;
	void Update() override;
	void OnExit() override;
};

