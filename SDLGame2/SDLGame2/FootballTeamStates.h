#pragma once
#include "State.h"
#include "FootballTeam.h"


class AttackingState : public State<FootballTeam>
{
public:
	static AttackingState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new AttackingState();
		}
		return m_Instance;
	}

	void Enter(FootballTeam* _agent);
	void Execute(FootballTeam* _agent);
	void Exit(FootballTeam* _agent);
	bool OnMessage(FootballTeam* _agent, const Telegram& _telegram);

private:
	static AttackingState* m_Instance;
	AttackingState(){}
};


class DefendingState : public State<FootballTeam>
{
public:
	static DefendingState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new DefendingState();
		}
		return m_Instance;
	}

	void Enter(FootballTeam* _agent);
	void Execute(FootballTeam* _agent);
	void Exit(FootballTeam* _agent);
	bool OnMessage(FootballTeam* _agent, const Telegram& _telegram);

private:
	static DefendingState* m_Instance;
	DefendingState(){}
};


class PrepareForKickOffState : public State<FootballTeam>
{
public:
	static PrepareForKickOffState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new PrepareForKickOffState();
		}
		return m_Instance;
	}

	void Enter(FootballTeam* _agent);
	void Execute(FootballTeam* _agent);
	void Exit(FootballTeam* _agent);
	bool OnMessage(FootballTeam* _agent, const Telegram& _telegram);

private:
	static PrepareForKickOffState* m_Instance;
	PrepareForKickOffState(){}
};

