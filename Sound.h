#pragma once
#include "Types.h"

class Sound : public Singleton<Sound>
{
public:
	wstring _NowMp3;
	void PlayBGM(wstring path);
	void StopBGM();
	void PlayEFX(wstring path);
};

