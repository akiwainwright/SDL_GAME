#include "Ship.h"
#include "AnimatorComponent.h"
#include "Game.h"

Ship::Ship(Game* game, string _name, ActorState _state, Actor* _parent) : GameObject(game,_name,_state), mRightSpeed(0.0f)
, mDownSpeed(0.0f)
{
	// Create an animated sprite component
	//AnimatorComponent* asc = new AnimatorComponent(this);
	//std::vector<SDL_Texture*> anims = {
	//	game->GetTextures("Assets/Textures/Ship01.png"),
	//	game->GetTextures("Assets/Textures/Ship02.png"),
	//	game->GetTextures("Assets/Textures/Ship03.png"),
	//	game->GetTextures("Assets/Textures/Ship04.png"),
	//};
	//asc->SetAnimTextures(anims);

	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTextures("Assets/Textures/Ship01.png"));
}


void Ship::UpdateGameObject(float deltaTime)
{
	GameObject::UpdateGameObject(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos =GetTransform()-> GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	GetTransform()-> SetPosition(pos);
}

void Ship::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}
}