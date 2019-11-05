#include "DXUT.h"
#include "MousePointer.h"
#include "Sprite.h"
MousePointer::MousePointer()
{
	Create(L"MousePointer.png");
	isUI = true;
}

void MouseMNG::CreateMousePointer()
{
	mouse = new MousePointer();
}

void MouseMNG::MouseSet()
{
	mouse->_position = Director::GetInstance()->GetMousePos();
}

void MouseMNG::DeleteMouse()
{
	delete mouse;
}
