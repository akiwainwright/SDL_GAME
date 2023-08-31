#include "TextureManager.h"
#include<SDL_image.h>
#include "CustomMaths.h"
#include<iostream>
#include<utility>
#include "Game.h"

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

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), texSurface);

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
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_Textures[_textureID], &srcRect, &dstRect, 0, nullptr, _flip);
}

/// <summary>
/// Display a single frame from a spritesheet
/// </summary>
/// <param name="_textureID">Name of texture</param>
/// <param name="_xPos">x location to display the frame</param>
/// <param name="_yPos">y location to display the frame</param>
/// <param name="_width">width of spritesheet</param>
/// <param name="_height">height of spritesheet</param>
/// <param name="_rows">number of rows in spritesheet</param>
/// <param name="_cols">number of columns in sprite sheet</param>
/// <param name="_frameRow">row of frame to display</param>
/// <param name="_frameColumn">column of frame to display</param>
/// <param name="_flip">facing direction of sprite</param>
/// <param name="scale">scale of frame</param>
void TextureManager::DrawFrame(std::string _textureID, int _xPos, int _yPos, int _width, int _height, int _rows, int _cols, int _frameRow, int _frameColumn, SDL_RendererFlip _flip, float scale)
{
	int frameWidth = _width / _cols;
	int frameHeight = _height / _rows;

	Vector2 frameStart = { frameWidth * (float)(_frameColumn - 1), frameHeight * (float)(_frameRow - 1) };

	SDL_Rect srcRect = { (int)frameStart.x, (int)frameStart.y, frameWidth, frameHeight };
	SDL_Rect dstRect = { _xPos, _yPos, frameWidth * scale, frameHeight * scale };
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_Textures[_textureID], &srcRect, &dstRect, 0, nullptr, _flip);
}

//void TextureManager::SetRenderer(SDL_Renderer& _renderer)
//{
//	m_Renderer = &_renderer;
//}

TextureManager::TextureManager()
{
	//m_Renderer = nullptr;
}

