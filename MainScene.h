#pragma once
#include "Scene.h"
#include "Director.h"
#include "GameScene.h"
#include "MousePointer.h"
#include "Sprite.h"
#include "Button.h"
class MainScene : public Scene
{
public:

	Sprite* startbutton;
	MouseMNG* mouse;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

