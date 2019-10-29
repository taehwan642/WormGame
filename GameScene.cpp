#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "Game" << endl;
	asdf = new Worm();
	timer = 0;
	movetime = 1;
}

void GameScene::Update()
{
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new MainScene);

	timer += Time::deltaTime;

	if (timer > movetime)
	{
		asdf->WormMove();
		movetime += -0.0025;
		timer = 0;
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
