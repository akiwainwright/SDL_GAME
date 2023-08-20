#pragma once
#include <chrono>

class GameTime
{
public:
	GameTime();
	~GameTime();

	float GetDeltaTime();

private:

	
	std::chrono::steady_clock::time_point m_CurrentFrame;
};

