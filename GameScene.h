#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "Worm.h"
class GameScene :
	public Scene
{
public:
	Worm* asdf;
	float timer;
	float movetime;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

