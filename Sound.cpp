#include "DXUT.h"
#include "Sound.h"

void Sound::PlayBGM(wstring path)
{
	StopBGM();
	_NowMp3 = path;
	auto route = L"play " + _NowMp3;
	mciSendString(route.c_str(), NULL, NULL, NULL);
}

void Sound::StopBGM()
{
	auto route = L"stop " + _NowMp3;
	mciSendString(route.c_str(), NULL, NULL, NULL);
}

void Sound::PlayEFX(wstring path)
{
	sndPlaySound(path.c_str(), SND_ASYNC);
}