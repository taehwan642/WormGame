#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "Game" << endl;
	asdf = new Worm();
	timer = 0;
	movetime = 0.4f;
	FruitMNG::GetInstance()->SpawnFruit();
}

void GameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);

	if (asdf->IsScreenOut())
	{
		cout << "GG" << endl;
		Director::GetInstance()->ChangeScene(new MainScene);
	}

	timer += Time::deltaTime;

	if (timer > movetime)
	{
		asdf->WormMove();
		if (asdf->IsCollision())
		{
			Director::GetInstance()->ChangeScene(new MainScene);
		}
		timer = 0;
	}

	if (asdf->FruitCollide())
	{
		if(movetime >= 0.15f)
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
}

void GameScene::OnExit()
{
	asdf->DeleteAll();
	FruitMNG::GetInstance()->DeleteFruit();
}
