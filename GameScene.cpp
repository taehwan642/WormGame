#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	/*for (int y = 20; y <= 630; y += 30)
	{
		for (int x = 20; x <= 1230; x += 30)
		{
			if (y == 20 || y >= 600  || x == 20 || x >= 1200)
			{
				Sprite* wall = new Sprite();
				wall->Create(L"Wall.png");
				wall->isUI = true;
				wall->_position.x = x;
				wall->_position.y = y;
				walls.push_back(wall);
			}
		}
	}*/
	cout << "Game" << endl;
	asdf = new Worm();
	timer = 0;
	movetime = 0.4f;
	FruitMNG::GetInstance()->SpawnFruit();
	WallsMNG::GetInstance()->SetWallPosition();
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
		if (movetime >= 0.15f)
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
	WallsMNG::GetInstance()->DeleteWalls();
	FruitMNG::GetInstance()->DeleteFruit();
	/*for (auto it : walls)
	{
		delete it;
	}
	walls.clear();*/
}
