#include "GameTime.h"

using namespace std::chrono;

GameTime::GameTime()
{
	m_CurrentFrame = high_resolution_clock::now();
}

GameTime::~GameTime()
{
}

float GameTime::GetDeltaTime()
{
	steady_clock::time_point lastFrameTime = m_CurrentFrame;

	m_CurrentFrame = high_resolution_clock::now();

	duration<float> deltaTime = m_CurrentFrame - lastFrameTime;
	

	return deltaTime.count();
}
