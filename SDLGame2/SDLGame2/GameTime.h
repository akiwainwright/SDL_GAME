#pragma once
#include <chrono>

class GameTime
{
public:
	static GameTime* GetInstance();

	float GetDeltaTime();

	std::chrono::steady_clock::time_point GetCurrentFrame()const { return m_CurrentFrame; }

private:
	GameTime();
	static GameTime* s_Instance;

	std::chrono::steady_clock::time_point m_CurrentFrame;
};


