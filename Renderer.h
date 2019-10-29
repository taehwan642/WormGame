#pragma once
#include "Types.h"
#include "Node.h"

class Renderer : public Singleton<Renderer>
{
public:
	void AddRenderTarget(Node* node);
	void RemoveRenderTarget(Node* node);
	void Render();
private:
	list<Node*> _rendertargets;
	static bool Comp(Node* a,Node* b);
};

