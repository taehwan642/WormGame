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

bool Worm::IsCollision()
{
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
	if ((Head->_position.x > 1200) || (Head->_position.x < 50) || (Head->_position.y > 600) || (Head->_position.y < 50))
	{
		return true;
	}
	return false;
}

bool Worm::FruitCollide()
{
	for (auto it : FruitMNG::GetInstance()->fruits)
	{
		if (it->_visible)
		{
			if (it->GetDistance(Head) < 50)
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
