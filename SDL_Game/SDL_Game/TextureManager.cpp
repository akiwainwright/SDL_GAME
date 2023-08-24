#include "TextureManager.h"
#include<SDL_image.h>
#include<iostream>
#include<utility>

TextureManager* TextureManager::s_Instance = nullptr;

TextureManager* TextureManager::GetInstance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new TextureManager();
	}

	return s_Instance;
}

void TextureManager::CreateTexture(std::string _textureID, std::string _filePath)
{
	SDL_Surface* texSurface = IMG_Load(_filePath.c_str());

	if (!texSurface)
	{
		SDL_Log("Failed to create texture surface: %s", SDL_GetError());
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, texSurface);

	if (!texture)
	{
		SDL_Log(R"(Failed to create texture %s: %s)", _textureID, SDL_GetError());
		return;
	}

	m_Textures[_textureID] = texture;	
}

SDL_Texture* TextureManager::LoadTexture(std::string _textureID)
{
	return m_Textures[_textureID];
}

void TextureManager::DrawTexture(std::string _textureID, int _xPos, int _yPos, int _width, int _height, SDL_RendererFlip _flip)
{
	SDL_Rect srcRect = { 0, 0, _width, _height };
	SDL_Rect dstRect = { _xPos, _yPos, _width, _height };
	SDL_RenderCopyEx(m_Renderer, m_Textures[_textureID], &srcRect, &dstRect, 0, nullptr, _flip);
}

void TextureManager::SetRenderer(SDL_Renderer& _renderer)
{
	m_Renderer = &_renderer;
}

TextureManager::TextureManager()
{
	m_Renderer = nullptr;
}
