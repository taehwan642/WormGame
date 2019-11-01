#include "DXUT.h"
#include "Fruit.h"

Fruit::Fruit()
{
	Create(L"Fruit.png");
	isUI = true;
	_visible = false;
	randomnumber = rand() % 6;
}

void Fruit::Update()
{
	CollisionCheck();
}

void Fruit::CollisionCheck()
{
	RECT rect;
	if (IntersectRect(&rect, &GetRect(), &Worm::GetInstance()->Head->GetRect()))
	{
		cout << "COLLISION!" << endl;
		_visible = false;
	}
}

FruitMNG::FruitMNG()
{
	randompos = { 0,0 };
}

void FruitMNG::CreateFruit()
{
	for (int i = 0; i < 30; i++)
	{
		Fruit* fruit = new Fruit();
		fruits.push_back(fruit);
	}
}

void FruitMNG::SetFruitPosition()
{
	//  640 360
	//	590 360
	//	540 360
	//	490 360
	//	440 360
	//	390 360
	//	340 360
	//	290 360
	//	290 310
	//	290 260
	//	290 210
	//	290 160
	//	340 160
	//	390 160
	//	440 160
	//	490 160
	//	540 160
	//	590 160
	//	640 160
	//	690 160
	//	740 160
	//	790 160
	//	840 160
	//	840 210
	//	840 260
	//	840 310
	//	840 360
	//	840 410
	//	840 460
	//need to fix 
	for (auto thisFruit : fruits)
	{
		switch (thisFruit->randomnumber)
		{
		case 0:
			randompos = { 50,50 };
			break;
		case 1:
			randompos = { 100,100 };
			break;
		case 2:
			randompos = { 150,150 };
			break;
		case 3:
			randompos = { -50,-50 };
			break;
		case 4:
			randompos = { -100,-100 };
			break;
		case 5:
			randompos = { -150,-150 };

		default:
			break;
		}
		return;
	}
}

void FruitMNG::SpawnFruit()
{
	for (auto thisFruit : fruits)
	{
		if (!thisFruit->_visible)
		{
			thisFruit->_visible = true;
			switch (thisFruit->randomnumber)
			{
			case 0:
				randompos = { 50,50 };
				break;
			case 1:
				randompos = { 100,100 };
				break;
			case 2:
				randompos = { 150,150 };
				break;
			case 3:
				randompos = { -50,-50 };
				break;
			case 4:
				randompos = { -100,-100 };
				break;
			case 5:
				randompos = { -150,-150 };

			default:
				break;
			}
			//cout << "X : " << randompos.x << "Y : " << randompos.y << endl;
			thisFruit->_position = randompos;
			return;
		}
	}
}
