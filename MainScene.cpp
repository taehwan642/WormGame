#include "DXUT.h"
#include "MainScene.h"
void MainScene::Init()
{
	cout << "Main" << endl;
	MouseMNG::GetInstance()->CreateMousePointer();
	ShowCursor(FALSE);
}

void MainScene::Update()
{
	MouseMNG::GetInstance()->MouseSet();
	if (DXUTWasKeyPressed('P'))
		Director::GetInstance()->ChangeScene(new GameScene);
}

void MainScene::OnExit()
{

}
