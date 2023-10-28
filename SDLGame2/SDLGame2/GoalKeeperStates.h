#pragma once
#include "State.h"
#include "Events.h"



class FootballGoalKeeper;
class FootballPitch;


class GlobalKeeperState: public State<FootballGoalKeeper>
{
public:
	static GlobalKeeperState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new GlobalKeeperState();
		}
		return m_Instance;
	}
	void Enter(FootballGoalKeeper* _agent);
	void Execute(FootballGoalKeeper* _agent);
	void Exit(FootballGoalKeeper* _agent);
	bool OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram);

private:

	GlobalKeeperState(){}

	static GlobalKeeperState* m_Instance;
};



class TendGoalState: public State<FootballGoalKeeper>
{
public:
	static TendGoalState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new TendGoalState();
		}
		return m_Instance;
	}
	void Enter(FootballGoalKeeper* _agent);
	void Execute(FootballGoalKeeper* _agent);
	void Exit(FootballGoalKeeper* _agent);
	bool OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram);

private:

	TendGoalState(){}
	static TendGoalState* m_Instance;
};



class InterceptBallState: public State<FootballGoalKeeper>
{
public:
	static InterceptBallState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new InterceptBallState();
		}
		return m_Instance;
	}
	void Enter(FootballGoalKeeper* _agent);
	void Execute(FootballGoalKeeper* _agent);
	void Exit(FootballGoalKeeper* _agent);
	bool OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram);

private:

	InterceptBallState(){}

	static InterceptBallState* m_Instance;
};



class ReturnHomeState: public State<FootballGoalKeeper>
{
public:
	static ReturnHomeState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new ReturnHomeState();
		}
		return m_Instance;
	}
	void Enter(FootballGoalKeeper* _agent);
	void Execute(FootballGoalKeeper* _agent);
	void Exit(FootballGoalKeeper* _agent);
	bool OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram);

private:

	ReturnHomeState(){}

	static ReturnHomeState* m_Instance;
};



class PutBallBackInPlayState: public State<FootballGoalKeeper>
{
public:
	static PutBallBackInPlayState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new PutBallBackInPlayState();
		}
		return m_Instance;
	}
	void Enter(FootballGoalKeeper* _agent);
	void Execute(FootballGoalKeeper* _agent);
	void Exit(FootballGoalKeeper* _agent);
	bool OnMessage(FootballGoalKeeper* _agent, const Telegram& _telegram);

private:

	PutBallBackInPlayState(){}

	static PutBallBackInPlayState* m_Instance;
};

