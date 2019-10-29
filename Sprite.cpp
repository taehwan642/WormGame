#include "DXUT.h"
#include "Sprite.h"

Sprite::Sprite()
{
	_aniNum = 0;
	_timer = 0;
	_nowFrame = 0;
	texture = nullptr;
}

Sprite::~Sprite()
{
	Renderer::GetInstance()->RemoveRenderTarget(this);
}

void Sprite::Create(wstring filename)
{
	texture = TextureManager::GetInstance()->LoadTexture(filename);
	AddRenderTarget();
}

void Sprite::AddRenderTarget()
{
	Renderer::GetInstance()->AddRenderTarget(this);
}

bool Sprite::Animation(wstring path, int frame, float delay, int aninum)
{
	_timer += Time::deltaTime;
	if (_timer > delay)
	{
		if (_nowFrame == frame)
		{
			_nowFrame = 0;
			return true;
		}
		if (_aniNum != aninum)
		{
			_aniNum = aninum;
			_nowFrame = 0;
		}
		_nowFrame++;
		auto route = path + to_wstring(_nowFrame) + L".png";
		Create(route);

		_timer = 0;
	}
	return false;
}

float Sprite::GetDistance(Sprite* target)
{
	vector2 v2 = target->_position - _position;
	return sqrt(v2.x * v2.x + v2.y * v2.y);
}

void Sprite::LookAt(Sprite* target)
{
	v = target->_position - _position;
	_rotation = atan2(v.y, v.x);
}

bool Sprite::Goto(Sprite* target, float Speed)
{
	v = target->_position - _position;
	float size = sqrt(v.x * v.x + v.y * v.y);
	if (size < 100)
		return true;
	v.x /= size;
	v.y /= size;
	_rotation = atan2(v.y, v.x);

	_position += v * Speed * Time::deltaTime;
	return false;
}	

RECT Sprite::GetRect()
{
	RECT r = { 0,0,0,0 };
	r.right = _position.x + (texture->_info.Width / 2 * _scale.x);
	r.left = _position.x - (texture->_info.Width / 2 * _scale.x);
	r.top = _position.y - (texture->_info.Height / 2 * _scale.y);
	r.bottom = _position.y + (texture->_info.Height / 2 * _scale.y);
	return r;
}

void Sprite::Draw()
{

	if (!_visible)
		return;
	if (texture == nullptr)
		return;
	isUI ? Director::GetInstance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND) : Director::GetInstance()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

	Director::GetInstance()->GetSprite()->SetTransform(&GetMatrix());
	vector3 center = { _pivot.x * texture->_info.Width,_pivot.y * texture->_info.Height,0 };
	Director::GetInstance()->GetSprite()->Draw(texture->_texture, nullptr, &center, nullptr, _color);
	Director::GetInstance()->GetSprite()->End();
}
