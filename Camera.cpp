#include "DXUT.h"
#include "Camera.h"

void Camera::CameraInit()
{
	D3DXMatrixOrthoLH(&OM, 1280, -720, 0, 1);
	D3DXMatrixIdentity(&IM);
	_CameraSize = 5;
}

void Camera::Update()
{
	VM = D3DXMATRIX{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		-_camPos.x,-_camPos.y,0,1 };
	D3DXMatrixOrthoLH(&OM,1280 * _CameraSize,-720 * _CameraSize,0,1);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &OM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &IM);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &VM);
}
