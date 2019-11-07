#include "DXUT.h"
#include "ScoreScene.h"
void ScoreScene::Init()
{
	background = new Sprite();
	mainbutton = new Sprite();
	exitbutton = new Sprite();
	label = new Label;



	background->Create(L"ScoreBackGround.png");
	background->_position = { 625,325 };
	background->isUI = true;
	////////////////////////////////////////////
	mainbutton->Create(L"MainBTN.png");
	mainbutton->_position = { 1100,500 };
	mainbutton->isUI = true;
	////////////////////////////////////////////
	exitbutton->Create(L"Exit.png");
	exitbutton->_position = { 1100,580 };
	exitbutton->isUI = true;

	MouseMNG::GetInstance()->CreateMousePointer();
}

void ScoreScene::Update()
{
	//731 186
	MouseMNG::GetInstance()->MouseSet();
	label->Create_Label(Time::score, { 731,186 });
	if (Director::GetInstance()->OnMouseDown())
	{
		if (PtInRect(&mainbutton->GetRect(), Director::GetInstance()->p))
		{
			Director::GetInstance()->ChangeScene(new GameScene);
		}

		if (PtInRect(&exitbutton->GetRect(), Director::GetInstance()->p))
		{
			exit(1);
		}
	}

}

void ScoreScene::OnExit()
{
	MouseMNG::GetInstance()->DeleteMouse();
	label->Delete_Label();
	delete background;
	delete mainbutton;
	delete exitbutton;
}
