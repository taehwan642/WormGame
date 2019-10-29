#pragma once
#include "Sprite.h"
class Body : public Sprite
{
public:
	Body(Body* tail);
	Body();
	void Move();
	void SetDirection();
	Body* front;
	Body* next;
	Direction dir;
};

class Worm
{
public:
	Body* Head;
	Body* Tail;
	Body* Temp;
	Worm();
	void Insert();
	void SetMove();
	void WormMove();
	void AddBody();
	bool IsCollision();
	bool IsScreenOut();
	bool AteFruit();
};
