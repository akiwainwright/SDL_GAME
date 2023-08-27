#include "GameTime.h"

GameTime* GameTime::s_Instance = nullptr;

GameTime* GameTime::GetInstance()
{
	if (!s_Instance)
	{
		s_Instance = new GameTime();
	}

	return s_Instance;
}

using namespace std::chrono;

GameTime::GameTime()
{
	m_CurrentFrame = high_resolution_clock::now();
}

float GameTime::GetDeltaTime()
{
	steady_clock::time_point lastFrameTime = m_CurrentFrame;

	m_CurrentFrame = high_resolution_clock::now();

	duration<float> deltaTime = m_CurrentFrame - lastFrameTime;


	return deltaTime.count();
}
