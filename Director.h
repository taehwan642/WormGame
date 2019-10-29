#pragma once
#include "Types.h"
#include "Scene.h"

class Director : public Singleton<Director>
{
public:
	int ClickNum;
	bool OnMouseDown();
	bool OnMouse();
	bool OnMouseUp();
	void Init();
	LPD3DXSPRITE GetSprite() { return _sprite; };
	void UpdateGame();
	void ChangeScene(Scene* s);
	vector2 GetMousePos() { return vector2((float)p.x, (float)p.y); };
	POINT p;
private:
	LPD3DXSPRITE _sprite;
	Scene* _currentScene;
};

