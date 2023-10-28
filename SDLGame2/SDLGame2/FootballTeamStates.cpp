#include "FootballTeamStates.h"


AttackingState* AttackingState::m_Instance = nullptr;
DefendingState* DefendingState::m_Instance = nullptr;
PrepareForKickOffState* PrepareForKickOffState::m_Instance = nullptr;

void AttackingState::Enter(FootballTeam* _agent)
{
}

void AttackingState::Execute(FootballTeam* _agent)
{
}

void AttackingState::Exit(FootballTeam* _agent)
{
}

bool AttackingState::OnMessage(FootballTeam* _agent, const Telegram& _telegram)
{
	return false;
}




void DefendingState::Enter(FootballTeam* _agent)
{
}

void DefendingState::Execute(FootballTeam* _agent)
{
}

void DefendingState::Exit(FootballTeam* _agent)
{
}

bool DefendingState::OnMessage(FootballTeam* _agent, const Telegram& _telegram)
{
	return false;
}




void PrepareForKickOffState::Enter(FootballTeam* _agent)
{
}

void PrepareForKickOffState::Execute(FootballTeam* _agent)
{
}

void PrepareForKickOffState::Exit(FootballTeam* _agent)
{
}

bool PrepareForKickOffState::OnMessage(FootballTeam* _agent, const Telegram& _telegram)
{
	return false;
}
