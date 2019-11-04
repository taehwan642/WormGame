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
	pos.x = ((rand() % 20) + 2) * 50;
	pos.y = ((rand() % 11) + 2) * 50;
	cout << fruits.size() - 1 << endl;
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
