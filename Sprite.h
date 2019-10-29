#pragma once
#include "Node.h"
#include "Texture2D.h"
#include "Renderer.h"
#include "Director.h"
class Sprite :
	public Node
{
public:
	Sprite();
	~Sprite();

	void Create(wstring filename);
	void AddRenderTarget();

	bool Animation(wstring path, int frame, float delay, int aninum);
	int _nowFrame;
	int _aniNum;
	float _timer;

	float GetDistance(Sprite* target);
	void LookAt(Sprite* target);
	bool Goto(Sprite* target,float Speed);

	RECT GetRect();

	Texture2D* texture;

	void Draw() override;
};

