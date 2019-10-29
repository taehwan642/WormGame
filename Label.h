#pragma once
#include "Sprite.h"
#include "Node.h"
class Label : public Node
{
public:
	int Addpos;
	vector<Sprite*> sp;
	void Create_Label(int num);
	void Delete_Label();
};

