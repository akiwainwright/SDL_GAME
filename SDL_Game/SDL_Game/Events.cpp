#include "Events.h"
#include "GameObject.h"
#include "Game.h"


MessageDispatcher* MessageDispatcher::m_Instance = nullptr;

void MessageDispatcher::DispatchMessage(double _delay,class Actor* _sender, class Actor* _receiver, MessageType _msg, void* _extraInfo)
{
	auto receiver = m_Game->GetActor(_receiver);
	Telegram telegram(0, _sender, _receiver, _msg, _extraInfo);

	//if there's no delay, route the telegram immediately
	if (_delay <= 0)
	{
		Discharge(receiver, telegram);

	}
	else
	{
		//double currentTime = m_Clock->GetCurrentTime();
		//telegram.m_DispatchTime = 
		m_PriorityQueue.insert(telegram); 
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	double currentTime = 0.0f;//=
	//now peek at the queue to see if any telegrams need dispatching
	//remove all telegrams from the front of the queue that have gone past their sell-by date
	while (!m_PriorityQueue.empty() && m_PriorityQueue.begin()->m_DispatchTime < currentTime && m_PriorityQueue.begin()->m_DispatchTime > 0)
	{
		const Telegram& telegram = *m_PriorityQueue.begin();
		auto receiver = m_Game->GetActor(telegram.m_Receiver);
		Discharge(receiver, telegram);
		m_PriorityQueue.erase(m_PriorityQueue.begin());
	}


}

MessageDispatcher::~MessageDispatcher()
{
	delete m_Instance;
	m_Instance = nullptr;
}

void MessageDispatcher::Discharge(Actor* _receiver, const Telegram& _msg)
{
	if (!_receiver->HandleMessage(_msg))
	{
		//mesage not handled
	}
}

MessageDispatcher::MessageDispatcher()
{
}
