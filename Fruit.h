#pragma once
#include "Sprite.h"
class Fruit : public Sprite
{
public:
	Fruit();
	
};

class FruitMNG : public Singleton<FruitMNG>
{
	vector<Fruit> fruits;
};