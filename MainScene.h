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
	float aboutscaletimer;
	bool aboutclicked;
	Sprite* startbutton;
	Sprite* aboutbutton;
	Sprite* exitbutton;
	Sprite* about;
	Sprite* backGround;
	MouseMNG* mouse;
	void aboutScaleSetting();
	void Init() override;
	void Update() override;
	void OnExit() override;
};

