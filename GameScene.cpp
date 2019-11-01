#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "Game" << endl;
	asdf = new Worm();
	timer = 0;
	FruitCreateTimer = 0;
	movetime = 1;
	FruitMNG::GetInstance()->CreateFruit();
}

void GameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);

	/*asdf->IsCollision();

	asdf->IsCollision() ? cout << "TRUE" << endl : cout << "FALSE" << endl;*/


	timer += Time::deltaTime;
	FruitCreateTimer += Time::deltaTime;

	if (timer > movetime)
	{
		asdf->WormMove();
		timer = 0;
	}

	if (FruitCreateTimer > 0.1f)
	{
		FruitMNG::GetInstance()->SpawnFruit();
		FruitCreateTimer = 0;
	}

	if (DXUTWasKeyPressed('W'))
	{
		asdf->Head->dir = Up;
	}
	if (DXUTWasKeyPressed('S'))
	{
		asdf->Head->dir = Down;
	}
	if (DXUTWasKeyPressed('A'))
	{
		asdf->Head->dir = Left;
	}
	if (DXUTWasKeyPressed('D'))
	{
		asdf->Head->dir = Right;
	}

	if (DXUTWasKeyPressed(VK_SPACE))
	{
		asdf->Insert();
	}
}

void GameScene::OnExit()
{
}
