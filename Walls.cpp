#include "DXUT.h"
#include "Walls.h"

Walls::Walls()
{
	Create(L"Wall.png");
	isUI = true;
}

void WallsMNG::SetWallPosition()
{
	for (int y = 0; y < 14; y++)
	{
		for (int x = 0; x < 26; x++)
		{
			if (x == 0 || x == 25 || y == 0 || y == 13)
			{
				Walls* wall = new Walls();
				wall->_position.x = x * 50;
				wall->_position.y = y * 50;
				walls.push_back(wall);
			}

		}
	}

}

void WallsMNG::DeleteWalls()
{
	for (auto it : walls)
	{
		delete it;
	}
	walls.clear();
}

