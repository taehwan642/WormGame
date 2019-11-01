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
	_position = { 650,350 };
	dir = Down;
	next = nullptr;
	front = nullptr;
}

void Body::Move()
{
	cout << _position.x << " " << _position.y << endl;
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
bool Body::ForHeadCollision()
{
	return false;
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
	bods.push_back(body);
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
	//for (auto it : bods)
	//{
	//	RECT bodyRECT;
	//	if (IntersectRect(&bodyRECT, &Head->GetRect(), &it->GetRect()))
	//	{
	//		return true;
	//	}
	//}
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
	for (auto it : bods)
	{
		if (Head->dir == Right && Head->_position.x + 100 == it->_position.x)
		{
			return true;
		}
		if (Head->dir == Left && Head->_position.x + -100 == it->_position.x)
		{
			return true;
		}
		if (Head->dir == Up && Head->_position.y + -100 == it->_position.y)
		{
			return true;
		}
		if (Head->dir == Down && Head->_position.y + 100 == it->_position.y)
		{
			return true;
		}
		/*if (Head->_position.x == it->_position.x || Head->_position.y == it->_position.y)
			return true;*/
	}

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
