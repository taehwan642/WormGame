#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Label.h"
#include "MainScene.h"
#include "MousePointer.h"
class ScoreScene : public Scene
{
public:
	Sprite* background;
	Sprite* mainbutton;
	Sprite* exitbutton;
	Label* label;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

