#include "DXUT.h"
#include "Walls.h"

Walls::Walls()
{
	Create(L"Wall.png");
	isUI = true;
}

void WallsMNG::SetWallPosition()
{
	for (int y = 0; y < 23; y++)
	{
		for (int x = 0; x < 43; x++)
		{
			if (x == 0 || x == 41 || y == 0 || y == 21)
			{
				Walls* wall = new Walls();
				wall->_position.x = x * 30;
				wall->_position.y = y * 30;
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

