#include "SpriteComponent.h"
#include "GameObject.h"
#include "CustomMaths.h"

SpriteComponent::SpriteComponent(GameObject* owner, int drawOrder)
	:Component(owner)
	, mTexture(nullptr)
	, mDrawOrder(drawOrder)
	, mTexWidth(0)
	, mTexHeight(0)
{
	m_Owner->GetGameModeBase()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	m_Owner->GetGameModeBase()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		SDL_Rect r;
		// Scale the width/height by owner's scale
		r.w = static_cast<int>(mTexWidth * m_Owner->GetTransform()-> GetScale().x);
		r.h = static_cast<int>(mTexHeight * m_Owner->GetTransform()->GetScale().y);
		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(m_Owner->GetTransform()->GetPosition().x - r.w / 2);
		r.y = static_cast<int>(m_Owner->GetTransform()->GetPosition().y - r.h / 2);

		// Draw (have to convert angle from radians to degrees, and clockwise to counter)
		SDL_RenderCopyEx(renderer,
			mTexture,
			nullptr,
			&r,
			-radToDeg(m_Owner->GetTransform()->GetRotation()),
			nullptr,
			SDL_FLIP_NONE);

		

	}
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
	// Set width/height
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
	
}