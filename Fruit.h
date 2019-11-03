#pragma once
#include "Sprite.h"
#include "Worm.h"
class Fruit : public Sprite
{
public:
	Fruit();
};

class FruitMNG : public Singleton<FruitMNG>
{
public:
	vector<Fruit*> fruits;
	void SpawnFruit(); 
	void DeleteFruit();
};