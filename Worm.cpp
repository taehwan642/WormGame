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
	dir = Up;
	next = nullptr;
	front = nullptr;
}

void Body::Update()
{
	 
	
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
	SetRotation();
}

void Body::SetDirection()
{

}
void Body::SetRotation()
{
	switch (dir)
	{
	case Direction::Down:
		_rotation = 1.6f;
		break;
	case Direction::Up:
		_rotation = 4.74;
		break;
	case Direction::Left:
		_rotation = 3.15f;
		break;
	case Direction::Right:
		_rotation = 0;
		break;
	}
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
	bods.push_back(Head);

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
	////for (auto it : bods)
	////{
	////	RECT bodyRECT;
	////	if (IntersectRect(&bodyRECT, &Head->GetRect(), &it->GetRect()))
	////	{
	////		return true;
	////	}
	////}
	///*switch (dir)
	//{
	//case Direction::Down:
	//	_position.y += 50;
	//	break;
	//case Direction::Up:
	//	_position.y += -50;
	//	break;
	//case Direction::Left:
	//	_position.x += -50;
	//	break;
	//case Direction::Right:
	//	_position.x += 50;
	//	break;
	//}*/
	//for (auto it : bods)
	//{
	//	if (Head->dir == Right && Head->_position.x + 100 == it->_position.x)
	//	{
	//		return true;
	//	}
	//	if (Head->dir == Left && Head->_position.x + -100 == it->_position.x)
	//	{
	//		return true;
	//	}
	//	if (Head->dir == Up && Head->_position.y + -100 == it->_position.y)
	//	{
	//		return true;
	//	}
	//	if (Head->dir == Down && Head->_position.y + 100 == it->_position.y)
	//	{
	//		return true;
	//	}
	//	/*if (Head->_position.x == it->_position.x || Head->_position.y == it->_position.y)
	//		return true;*/
	//}

	//return false
	Temp = Head->next;
	while (Temp != NULL)
	{
		if (Head->_position == Temp->_position)
		{
			return true;
		}
		Temp = Temp->next;
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

bool Worm::FruitCollide()
{
	for (auto it : FruitMNG::GetInstance()->fruits)
	{
		if (it->_visible)
		{
			if (it->_position == Head->_position)
			{
				FruitMNG::GetInstance()->SpawnFruit();
				Insert();
				it->_visible = false;
				return true;
			}
		}
	}
	return false;
}

void Worm::DeleteAll()
{
	for (auto it : bods)
	{
		delete it;
	}
	bods.clear();
}
