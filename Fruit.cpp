#include "DXUT.h"
#include "Fruit.h"

Fruit::Fruit()
{
	Create(L"Fruit.png");
	isUI = true;
}


void FruitMNG::SpawnFruit()
{
	Fruit* fruit = new Fruit();
	fruits.push_back(fruit);
	vector2 pos;
	pos.x = ((rand() % 24) + 1) * 50;
	pos.y = ((rand() % 12) + 1) * 50;
	fruit->_position = pos;
}

void FruitMNG::DeleteFruit()
{
	for (auto it : fruits)
	{
		delete it;
	}
	fruits.clear();
}
