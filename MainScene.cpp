#include "DXUT.h"
#include "MainScene.h"
void MainScene::Init()
{
	startbutton = new Sprite();
	startbutton->Create(L"StartBTN.png");
	MouseMNG::GetInstance()->CreateMousePointer();
	startbutton->_position = { 600,300 };
	startbutton->isUI = true;
	cout << "Main" << endl;
	//ShowCursor(FALSE);
}

void MainScene::Update()
{
	MouseMNG::GetInstance()->MouseSet();
	if (Director::GetInstance()->OnMouseDown())
	{
		if (PtInRect(&startbutton->GetRect(), Director::GetInstance()->p))
		{
			Director::GetInstance()->ChangeScene(new GameScene);
		}
	}

}

void MainScene::OnExit()
{
	MouseMNG::GetInstance()->DeleteMouse();
	delete startbutton;
}
