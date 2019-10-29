#pragma once
#include "Types.h"

class Camera : public Singleton<Camera>
{
public:
	void CameraInit();
	void Update();

	void SetPos(vector2 v) { _camPos.x = v.x, _camPos.y = v.y; };

	float _CameraSize;
private:
	D3DXMATRIX OM;
	D3DXMATRIX IM;
	D3DXMATRIX VM;

	vector2 _camPos;
};

