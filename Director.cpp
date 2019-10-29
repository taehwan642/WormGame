#include "DXUT.h"
#include "Director.h"
#include "Renderer.h"
bool Director::OnMouseDown()
{
	if (ClickNum == 1)
	{
		ClickNum++;
		return true;
	}
	return false;
}

bool Director::OnMouse()
{
	if (ClickNum == 2)
	{
		return true;
	}
	return false;
}

bool Director::OnMouseUp()
{
	if (ClickNum == 3)
	{
		ClickNum = 0;
		return true;
	}
	return false;
}

void Director::Init()
{
	ClickNum = 0;
	_sprite = nullptr;
	_currentScene = nullptr;

	D3DXCreateSprite(DXUTGetD3D9Device(),&_sprite);
}

void Director::UpdateGame()
{
	if (_currentScene)
		_currentScene->Update();
	Renderer::GetInstance()->Render();

	GetCursorPos(&p);
	ScreenToClient(DXUTGetHWND(), &p);
}

void Director::ChangeScene(Scene* s)
{
	if (_currentScene)
		_currentScene->OnExit();
	_currentScene = s;
	_currentScene->Init();
}
