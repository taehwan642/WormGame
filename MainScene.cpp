#include "DXUT.h"
#include "MainScene.h"
void MainScene::aboutScaleSetting()
{
	if (aboutscaletimer > 0.00001f && aboutclicked && about->_scale.x < 1 && about->_scale.y < 1)
	{
		about->_scale.y += 0.01f;
		about->_scale.x += 0.01f;
		aboutscaletimer = 0;
	}
}
void MainScene::Init()
{
	startbutton = new Sprite();
	aboutbutton = new Sprite();
	exitbutton = new Sprite();
	about = new Sprite();
	backGround = new Sprite();
	
	aboutscaletimer = 0;
	aboutclicked = false;

	backGround->Create(L"BackGround.png");
	backGround->isUI = true;
	backGround->_position = { 625,325 };
	///////////////////////////////////////////////////
	startbutton->Create(L"StartBTN.png");
	startbutton->_position = { 1100,420 };
	startbutton->isUI = true;
	///////////////////////////////////////////////////
	aboutbutton->Create(L"AboutBTN.png");
	aboutbutton->_position = { 1100,500 };
	aboutbutton->isUI = true;
	///////////////////////////////////////////////////
	exitbutton->Create(L"Exit.png");
	exitbutton->_position = { 1100, 580 };
	exitbutton->isUI = true;
	///////////////////////////////////////////////////
	about->Create(L"About.png");
	about->_position = { 625,325 };
	about->_scale = { 0,0 };
	about->isUI = true;



	cout << "Main" << endl;
	MouseMNG::GetInstance()->CreateMousePointer();
	ShowCursor(FALSE);
}

void MainScene::Update()
{
	aboutscaletimer += Time::deltaTime;
	MouseMNG::GetInstance()->MouseSet();

	if (Director::GetInstance()->OnMouseDown())
	{
		if (PtInRect(&startbutton->GetRect(), Director::GetInstance()->p))
		{
			Director::GetInstance()->ChangeScene(new GameScene);
		}
		if (PtInRect(&aboutbutton->GetRect(), Director::GetInstance()->p))
		{
			aboutclicked = true;
		}
		if (PtInRect(&exitbutton->GetRect(), Director::GetInstance()->p))
		{
			exit(1);
		}
		if (PtInRect(&about->GetRect(), Director::GetInstance()->p))
		{
			aboutclicked = false;
			about->_scale = { 0,0 };
		}
	}
	aboutScaleSetting();
	//cout << MouseMNG::GetInstance()->mouse->_position.x << " " << MouseMNG::GetInstance()->mouse->_position.y << endl;
}

void MainScene::OnExit()
{
	MouseMNG::GetInstance()->DeleteMouse();
	delete startbutton;
	delete backGround;
	delete exitbutton;
	delete aboutbutton;
	delete about;
}
