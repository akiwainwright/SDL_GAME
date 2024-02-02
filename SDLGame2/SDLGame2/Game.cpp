#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Animator.h"
#include "GameTime.h"
#include "GameModeBase.h"
#include "TextureManager.h"
#include <SDL_image.h>

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
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	//TextureManager::GetInstance()->SetRenderer(*m_Renderer);
	MainMenu = new GameModeBase();
	

	//SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	return true;
}

void Game::RunLoop()
{
	

	while (m_IsRunning)
	{
		m_deltaTime = GameTime::GetInstance()->GetDeltaTime();
		
		//MainMenu->ProcessInput();
		//MainMenu->UpdateGame(m_deltaTime);
		//MainMenu->RenderLoop(m_deltaTime);

		ProcessInput();
		UpdateGame(m_deltaTime);
		RenderLoop(m_deltaTime);
	}
}

void Game::Shutdown()
{
	while (!m_Actors.empty())
	{
		delete m_Actors.back();
	}

	SDL_DestroyRenderer(m_Renderer);

	SDL_DestroyWindow(m_Window);

	SDL_Quit();
}

void Game::AddActor(Actor* _actor)
{
	if (_actor == nullptr) return;
	auto iter = std::find(m_Actors.begin(), m_Actors.end(), _actor);
	if (iter != m_Actors.end())
	{
		m_PendingActors.emplace_back(_actor);
	}
}

void Game::RemoveActor(Actor* _actor)
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

Actor* Game::GetActor(Actor* _actor)
{
	auto iter = std::find(m_Actors.begin(), m_Actors.end(), _actor);

	if (iter[0] ==nullptr)
	{
		return nullptr;
	}
	return iter[0];

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
	const Uint8* state = SDL_GetKeyboardState(NULL);
	m_UpdatingActor = true;
	for (auto actors : m_Actors)
	{
		GameObject* obj = dynamic_cast<GameObject*>(actors);
		if (obj)
		{
			obj->ProcessInput(state);
		}
	}
	m_UpdatingActor = false;
}

void Game::UpdateGame(float _deltaTime)
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

void Game::RenderLoop(float _deltatime)
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);


	TextureManager::GetInstance()->DrawFrame("Player Run", 250, 250, 768, 64, 1, 8, 1, 8, SDL_FLIP_NONE, 2);
	//m_TestObject->GetComponent<Animator>()->PlayAnimation(_deltatime);
	SDL_RenderPresent(m_Renderer);
}

SDL_Texture* Game::GetTextures(const string& fileName)
{

		SDL_Texture* tex = nullptr;
		// Is the texture already in the map?
		auto iter = m_Textures.find(fileName);
		if (iter != m_Textures.end())
		{
			tex = iter->second;
		}
		else
		{
			// Load from file
			SDL_Surface* surf = IMG_Load(fileName.c_str());
			if (!surf)
			{
				SDL_Log("Failed to load texture file %s", fileName.c_str());
				return nullptr;
			}

			// Create texture from surface
			tex = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surf);
			SDL_FreeSurface(surf);
			if (!tex)
			{
				SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
				return nullptr;
			}

			m_Textures.emplace(fileName.c_str(), tex);
		}
		return tex;
	
}
