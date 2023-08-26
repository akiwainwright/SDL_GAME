#pragma once
#include <chrono>

class GameTime
{
public:
	static GameTime* GetInstance();

	float GetDeltaTime();

private:
	GameTime();
	static GameTime* s_Instance;
	
	std::chrono::steady_clock::time_point m_CurrentFrame;
};

