#pragma once
#include "State.h"
#include "FootballFieldPlayer.h"

class GlobalFieldPlayerState : public State<FootballFieldPlayer>
{
public:
	
	//~GlobalFieldPlayerState();
	static GlobalFieldPlayerState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new GlobalFieldPlayerState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram& _telegram);
	

private:
	static GlobalFieldPlayerState* m_Instance;
	GlobalFieldPlayerState(){}
};



class ChaseBallState : public State<FootballFieldPlayer>
{
public:

	static ChaseBallState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new ChaseBallState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static ChaseBallState* m_Instance;
	ChaseBallState() {}
};



class DribbleState : public State<FootballFieldPlayer>
{
public:

	static DribbleState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new DribbleState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static DribbleState* m_Instance;
	DribbleState() {}
};



class ReturnToHomeRegionState : public State<FootballFieldPlayer>
{
public:

	static ReturnToHomeRegionState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new ReturnToHomeRegionState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static ReturnToHomeRegionState* m_Instance;
	ReturnToHomeRegionState() {}
};




class WaitState : public State<FootballFieldPlayer>
{
public:

	static WaitState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new WaitState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static WaitState* m_Instance;
	WaitState() {}
};



class KickBallState : public State<FootballFieldPlayer>
{
public:

	static KickBallState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new KickBallState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static KickBallState* m_Instance;
	KickBallState() {}
};




class ReceiveBallState : public State<FootballFieldPlayer>
{
public:

	static ReceiveBallState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new ReceiveBallState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static ReceiveBallState* m_Instance;
	ReceiveBallState() {}
};



class SupportAttackerState : public State<FootballFieldPlayer>
{
public:

	static SupportAttackerState* Instance() {
		if (m_Instance == nullptr)
		{
			m_Instance = new SupportAttackerState();
		}

		return m_Instance;
	}
	void Enter(FootballFieldPlayer* _agent);
	void Execute(FootballFieldPlayer* _agent);
	void Exit(FootballFieldPlayer* _agent);
	bool OnMessage(FootballFieldPlayer* _agent, const Telegram&);


private:
	static SupportAttackerState* m_Instance;
	SupportAttackerState() {}
};
