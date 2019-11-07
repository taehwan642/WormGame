#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "Game" << endl;
	asdf = new Worm();
	label = new Label();
	timer = 0;
	movetime = 0.4f;
	Time::score = 0;
	FruitMNG::GetInstance()->SpawnFruit();
	WallsMNG::GetInstance()->SetWallPosition();
}

void GameScene::Update()
{
	label->Create_Label(Time::score, {10,10});

	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new ScoreScene);

	if (asdf->IsScreenOut())
	{
		Director::GetInstance()->ChangeScene(new ScoreScene);
	}

	timer += Time::deltaTime;

	if (timer > movetime)
	{
		asdf->WormMove();
		if (asdf->IsCollision())
		{
			Director::GetInstance()->ChangeScene(new ScoreScene);
		}
		timer = 0;
	}

	if (asdf->FruitCollide())
	{
		if (movetime >= 0.15f)
			movetime -= 0.05f;

		Time::score++;
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
	WallsMNG::GetInstance()->DeleteWalls();
	FruitMNG::GetInstance()->DeleteFruit();
	label->Delete_Label();
}
