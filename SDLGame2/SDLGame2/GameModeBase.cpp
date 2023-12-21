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
	return nullptr;
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
