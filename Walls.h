#pragma once
#include "Sprite.h"
class Walls :
	public Sprite
{
public:
	Walls();
};

class WallsMNG : public Singleton<WallsMNG>
{
public:
	vector<Walls*> walls;
	void SetWallPosition();
	void DeleteWalls();
};