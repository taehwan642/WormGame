#include "DXUT.h"
#include "Fruit.h"

Fruit::Fruit()
{
	Create(L"Fruit.png");
	isUI = true;
}


void FruitMNG::SpawnFruit()
{
	//2 18
	Fruit* fruit = new Fruit();
	fruits.push_back(fruit);
	vector2 pos;
	pos.x = ((rand() % 10) + 2) * 50;
	pos.y = ((rand() % 10) + 2) * 50;
	fruit->_position = pos;
	cout << fruits.size() - 1 << endl;
}

void FruitMNG::DeleteFruit()
{
	for (auto it : fruits)
	{
		delete it;
	}
	fruits.clear();
}
