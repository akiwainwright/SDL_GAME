#pragma once
#include<string>
#include<SDL.h>
#include<map>

class TextureManager
{
public:

	static TextureManager* GetInstance();

	void CreateTexture(std::string _textureID, std::string _filePath);

	SDL_Texture* LoadTexture(std::string _textureID);

	void DrawTexture(std::string _textureID, float _xPos, float _yPos, int _width, int _height, SDL_RendererFlip _flip);

	void DrawFrame(std::string _textureID, float _xPos, float _yPos, int _width, int _height, int _rows, int _cols, int _frameRow, int frameColumn, SDL_RendererFlip _flip, float scale = 1);

	//void SetRenderer(SDL_Renderer& _renderer);


private:
	TextureManager();
	static TextureManager* s_Instance;

	std::map<std::string, SDL_Texture*> m_Textures;

	//SDL_Renderer* m_Renderer;

};

