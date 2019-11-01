#pragma once
#include "Sprite.h"
#include "Worm.h"
class Fruit : public Sprite
{
public:
	Fruit();
	int randomnumber;
	void Update() override;
	void CollisionCheck();
};

class FruitMNG : public Singleton<FruitMNG>
{
public:
	vector<Fruit*> fruits;
	vector2 randompos;
	FruitMNG();
	void CreateFruit();
	void SetFruitPosition();
	void SpawnFruit(); 
};