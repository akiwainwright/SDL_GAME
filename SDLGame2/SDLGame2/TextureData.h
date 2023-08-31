#pragma once

#include <string>
#include <SDL_image.h>

struct TextureData
{
	std::string m_TexturePath;

	SDL_Texture* m_Texture = nullptr;

	float m_TextureWidth = 0.0f;
	float m_TextureHeight = 0.0f;

	int m_NumOfColumns = 0;
	int m_NumOfRows = 0;
};