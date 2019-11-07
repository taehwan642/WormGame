#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "MainScene.h"
#include "ScoreScene.h"
#include "Label.h"
#include "Worm.h"
#include "Fruit.h"
#include "Walls.h"
class GameScene :
	public Scene
{
public:
	Worm* asdf;
	Label* label;
	float timer;
	float movetime;
	void Init() override;
	void Update() override;
	void OnExit() override;
};

