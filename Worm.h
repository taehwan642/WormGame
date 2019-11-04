#pragma once
#include "Sprite.h"
#include "Fruit.h"
class Body : public Sprite
{
public:
	Body(Body* tail);
	Body();
	void Move();
	void SetRotation();
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
	vector<Body*> bods;
	Worm();
	void Insert();
	void SetMove();
	void WormMove();
	bool IsCollision();
	bool IsScreenOut();
	bool FruitCollide();
	void DeleteAll();
};
