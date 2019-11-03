#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "Game" << endl;
	asdf = new Worm();
	timer = 0;
	FruitCreateTimer = 0;
	movetime = 0.3f;
	FruitMNG::GetInstance()->SpawnFruit();
}

void GameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);

	//asdf->IsCollision();

	


	timer += Time::deltaTime;
	FruitCreateTimer += Time::deltaTime;

	if (timer > movetime)
	{
		asdf->WormMove();
		if (asdf->IsCollision())
		{
			Director::GetInstance()->ChangeScene(new GameScene);
		}
		timer = 0;
	}

	if (asdf->FruitCollide())
	{
		if(movetime >= 0.1f)
			movetime -= 0.05f;
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
	asdf->DeleteAll();
}
