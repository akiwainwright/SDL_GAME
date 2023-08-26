#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Animator.h"
#include "GameTime.h"
#include <iostream>


Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;
	m_IsRunning = true;

	m_TestObject = new GameObject(this, "test", EActive);

	m_deltaTime = GameTime::GetInstance()->GetDeltaTime();
}

Game::~Game()
{
}

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Unable to initialise SDL: %s", SDL_GetError());

		return false;
	}

	m_Window = SDL_CreateWindow("SDL_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);

	if (!m_Window)
	{
		SDL_Log("Failed to create window: %s ", SDL_GetError());

		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!m_Renderer)
	{
		SDL_Log("Renderer Unsuccessful:  %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->SetRenderer(*m_Renderer);
	TextureManager::GetInstance()->CreateTexture("Player Run", "Assets/Textures/noBKG_KnightRun_strip.png");

	m_TestObject->AddComponent(new Animator(m_TestObject));
	m_TestObject->GetComponent<Animator>()->SetAnimValues(768, 64, 1, 8, 1, 8, 30.0f);

	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	return true;
}

void Game::RunLoop()
{
	while (m_IsRunning)
	{
		m_deltaTime = GameTime::GetInstance()->GetDeltaTime();
		ProcessInput();
		UpdateGame(m_deltaTime);
		RenderLoop(m_deltaTime);
	}
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(m_Renderer);

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
}

void Game::ProcessInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::UpdateGame(float _deltaTime)
{
	
}

void Game::RenderLoop(float _deltatime)
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	
	//TextureManager::GetInstance()->DrawFrame("Player Run", 250, 250, 768, 64, 1, 8, 1, 8, SDL_FLIP_NONE, 2);
	m_TestObject->GetComponent<Animator>()->PlayAnimation(_deltatime);
	SDL_RenderPresent(m_Renderer);
}

