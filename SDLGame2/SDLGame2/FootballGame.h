#pragma once
#include "GameModeBase.h"


class FootballGame : GameModeBase
{
public:
	FootballGame();
	~FootballGame();

	class FootballPitch* m_Pitch;

private:

};

FootballGame::FootballGame()
{
}

FootballGame::~FootballGame()
{
}