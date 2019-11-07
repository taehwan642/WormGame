#pragma once

template <class T>

class Singleton
{
private:
	static T* _insntance;
public:
	static T* GetInstance()
	{
		if (_insntance == nullptr)
			_insntance = new T();
		return _insntance;
	}
};

template <class T> T* Singleton<T>::_insntance = nullptr;

class Time
{
public:
	static float deltaTime;
	static float timeScale;
	static int score;
};
