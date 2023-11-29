#include "GameModeBase.h"
#include <SDL.h>
#include "Events.h"
#include "Game.h"
#include "GameObject.h"
#include "Animator.h"
#include "TextureManager.h"


GameModeBase::GameModeBase()
{
	m_TestObject = nullptr;
	

	SetUpGameObjects();
}

Actor* GameModeBase::GetActor(Actor* _actor)
{
	auto iter = std::find(m_Actors.begin(), m_Actors.end(), _actor);

	if (iter[0] == nullptr)
	{
		return nullptr;
	}
	return iter[0];

}

void GameModeBase::ProcessInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_QUIT:
			Game::GetInstance()->SetRunning(false);

			break;
		default:
			break;
		}
	}
}

void GameModeBase::UpdateGame(float _deltaTime)
{
	MessageDispatcher::Instance()->DispatchDelayedMessages();

	m_UpdatingActor = true;
	for (auto actor : m_Actors)
	{
		actor->Update(_deltaTime);

	}
	m_UpdatingActor = false;
	for (auto pending : m_PendingActors)
	{
		pending->Update(_deltaTime);
		m_Actors.emplace_back(pending);
	}
	m_PendingActors.clear();

	vector<Actor*> deadActor;
	for (auto actor : m_Actors)
	{
		if (actor->GetState() == ActorState::EDead)
		{
			deadActor.emplace_back(actor);
		}
	}

	for (auto actors : deadActor)
	{
		delete actors;
	}

}

void GameModeBase::RenderLoop(float _deltaTime)
{
	SDL_SetRenderDrawColor(Game::GetInstance()->GetRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(Game::GetInstance()->GetRenderer());
	SDL_SetRenderDrawColor(Game::GetInstance()->GetRenderer(), 255, 255, 255, 255);

	m_TestObject->GetComponent<Animator>()->PlayAnimation(_deltaTime);
	SDL_RenderPresent(Game::GetInstance()->GetRenderer());
}

void GameModeBase::SetUpGameObjects()
{
	TextureManager::GetInstance()->CreateTexture("Player Run", "Assets/Textures/noBKG_KnightRun_strip.png");

	m_TestObject = new GameObject(this, "test", EActive);

	m_TestObject->AddComponent(new Animator(m_TestObject));
	m_TestObject->GetComponent<Animator>()->SetAnimValues(768, 64, 1, 8, 1, 8, 30.0f);
}

void GameModeBase::AddActor(Actor* _actor)
{

}

void GameModeBase::RemoveActor(Actor* _actor)
{
	auto iter = std::find(m_PendingActors.begin(), m_PendingActors.end(), _actor);
	if (iter != m_PendingActors.end())
	{
		iter_swap(iter, m_PendingActors.end() - 1);
		m_PendingActors.pop_back();
	}

	iter = std::find(m_Actors.begin(), m_Actors.end(), _actor);
	if (iter != m_Actors.end())
	{
		iter_swap(iter, m_Actors.end() - 1);
		m_Actors.pop_back();
	}
}
