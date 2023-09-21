#include "TextureComponent.h"

TextureComponent::TextureComponent(class GameObject* _owner, std::string _textureID, float _width, float _height, int _rows, int _cols) : Component(_owner)
{
	m_TextureID = _textureID;

	m_TextureWidth = _width;
	m_TextureHeight = _height;

	m_NumOfRows = _rows;
	m_NumOfColumns = _cols;
}

TextureComponent::~TextureComponent()
{
}

