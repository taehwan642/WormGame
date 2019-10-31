#pragma once
#include "Sprite.h"
class Body : public Sprite
{
public:
	Body(Body* tail);
	Body();
	void Move();
	void SetDirection();
	bool ForHeadCollision();
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
	void AddBody();
	bool IsCollision();
	bool IsScreenOut();
	bool AteFruit();
};
