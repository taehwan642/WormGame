#include "DXUT.h"
#include "MainScene.h"
void MainScene::Init()
{
	cout << "Main" << endl;
}

void MainScene::Update()
{

	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new GameScene);

	
}

void MainScene::OnExit()
{

}
