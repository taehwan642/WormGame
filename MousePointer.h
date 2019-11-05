#pragma once
#include "Sprite.h"
#include "Director.h"
class MousePointer :
	public Sprite
{
public:
	MousePointer();
};

class MouseMNG : public Singleton<MouseMNG>
{
public:
	MousePointer* mouse;

	void CreateMousePointer();
	void MouseSet();
	void DeleteMouse();
};