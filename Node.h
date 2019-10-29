#pragma once
class Node
{
public:
	Node();
	virtual ~Node() {};

	vector2 _position;
	vector2 _scale;
	vector2 _pivot;
	float _rotation;
	bool _visible; 
	COLOR _color;
	int _layer;
	bool isUI;
	vector2 v;


	D3DXMATRIX GetMatrix();

	virtual void Update() {};
	virtual void Draw() {};

};

