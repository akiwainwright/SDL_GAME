#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Animator.h"
#include "GameTime.h"
#include "GameModeBase.h"

Game* Game::s_Instance = nullptr;

Game* Game::GetInstance()
{
	if (!s_Instance)
	{
		s_Instance = new Game();
	}

	return s_Instance;
}

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;
	m_IsRunning = true;

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

	//TextureManager::GetInstance()->SetRenderer(*m_Renderer);

	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	return true;
}

void Game::RunLoop()
{
	MainMenu = new GameModeBase();

	while (m_IsRunning)
	{
		m_deltaTime = GameTime::GetInstance()->GetDeltaTime();
		
		MainMenu->ProcessInput();
		MainMenu->UpdateGame(m_deltaTime);
		MainMenu->RenderLoop(m_deltaTime);
	}
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(m_Renderer);

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
}

void Game::AddActor(Actor* _actor)
{
}

void Game::RemoveActor(Actor* _actor)
{

}


