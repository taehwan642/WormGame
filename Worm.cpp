#include "DXUT.h"
#include "Worm.h"

Body::Body(Body* tail)
{
	Create(L"JIRUNG.png");
	isUI = true;
	_visible = true;
	next = nullptr;
	front = nullptr;
	_color.r = 0;
	dir = tail->dir;
	_position = tail->_position;

	switch (dir)
	{
	case Direction::Down:
		_position.y += -50;
		break;
	case Direction::Up:
		_position.y += 50;
		break;
	case Direction::Left:
		_position.x += 50;
		break;
	case Direction::Right:
		_position.x += -50;
		break;
	}
}

Body::Body()
{
	Create(L"JIRUNG.png");
	isUI = true;
	_visible = true;
	_position = { 640,360 };
	dir = Down;
	next = nullptr;
	front = nullptr;
}


void Body::Move()
{
	switch (dir)
	{
	case Direction::Down:
		_position.y += 50;
		break;
	case Direction::Up:
		_position.y += -50;
		break;
	case Direction::Left:
		_position.x += -50;
		break;
	case Direction::Right:
		_position.x += 50;
		break;
	}
}

void Body::SetDirection()
{

}
///////////////////////////////////////////////////////
Worm::Worm()
{
	Head = new Body();
	Tail = Head;
}

void Worm::Insert()
{
	Body* body = new Body(Tail);
	body->front = Tail;
	Tail->next = body;
	Tail = body;
}

void Worm::SetMove()
{
	Temp = Tail;
	while (Temp != Head)
	{
		Temp->dir = Temp->front->dir;
		Temp = Temp->front;
	}
}

void Worm::WormMove()
{
	Temp = Head;
	while (Temp != NULL)
	{
		Temp->Move();
		Temp = Temp->next;
	}
	SetMove();
}

void Worm::AddBody()
{

}

bool Worm::IsCollision()
{
	/*switch (dir)
	{
	case Direction::Down:
		_position.y += 50;
		break;
	case Direction::Up:
		_position.y += -50;
		break;
	case Direction::Left:
		_position.x += -50;
		break;
	case Direction::Right:
		_position.x += 50;
		break;
	}*/
	return false;
}

bool Worm::IsScreenOut()
{

	return false;
}

bool Worm::AteFruit()
{

	return false;
}
