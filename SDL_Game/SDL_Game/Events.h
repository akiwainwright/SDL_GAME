#pragma once
#include "BasicIncludes.h"

enum MessageType
{
	MsgExample
};

struct Telegram
{
	//the entity that sent this telegram
	class Actor* m_Sender;

	//the entity that received this telegram
	class Actor* m_Receiver;

	//the messages itself. These are enumerators
	MessageType m_Msg;

	//messages can be dispatched immediately or delayed for a specific amount of time.
	//if a delay is necessary, this field is stamped with the time
	//the message should be dispatched
	double m_DispatchTime;

	//any additional info that may acompany the message
	void* m_ExtraInfo;

	Telegram(double _dispatchTime, class Actor* _sender, class Actor* _receiver, MessageType _msg, void* _extraInfo) {
		m_DispatchTime = _dispatchTime;
		m_Sender = _sender;
		m_Receiver = _receiver;
		m_Msg = _msg;
		m_ExtraInfo = _extraInfo;
	}
};


class MessageDispatcher
{
public:

	static MessageDispatcher* Instance() { return m_Instance = (m_Instance != nullptr) ? m_Instance : new MessageDispatcher(); }

	void DispatchMessage(double _delay, class Actor* _sender, class Actor* _receiver, MessageType _msg, void* _extraInfo);

	//send out any delay messages. this method is called each time through the main game loop
	void DispatchDelayedMessages();

	inline void SetGame(class Game* _game) {
		m_Game = _game;
	}

	~MessageDispatcher();

private:
	static MessageDispatcher* m_Instance;
	//the set is used as the container for the delayed messages because of the benefit of automatic sorting and avoidance of duplicates. 
	//Messages are sorted by their dispatch time
	set<Telegram> m_PriorityQueue;

	//this method is utilized by DispatchMessage or DispatchDelayedMessages
	//this method calls the message handling member function of the receiving entity(m_Receiver) wiith the telegram
	void Discharge(class Actor* _receiver, const Telegram& _msg);

	MessageDispatcher();

	class Game* m_Game;

};

