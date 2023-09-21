#pragma once
#include "Component.h"
#include <string>

class TextureComponent : public Component
{
public:
	TextureComponent(class GameObject* _owner, std::string _textureID, float _width, float _height, int _rows, int _cols);
	~TextureComponent();


	//Getters
	inline std::string GetTextureID() { return m_TextureID; }

	inline float GetTextureWidth() { return m_TextureWidth; }
	inline float GetTextureHeight() { return m_TextureHeight; }

	inline int GetTextureRows() { return m_NumOfRows; };
	inline int GetTextureCols() { return m_NumOfColumns; };

	//Setters
	inline void SetTextureID(std::string _textureID) { m_TextureID = _textureID; }

	inline void SetTextureWidth(float _width) { m_TextureWidth = _width; }
	inline void SetTextureHeight(float _height) { m_TextureHeight = _height; }

	inline void SetNumOfRows(int _rows) { m_NumOfRows = _rows; }
	inline void SetNumOfColumns(int _cols) { m_NumOfColumns = _cols; }

private:
	std::string m_TextureID;

	float m_TextureWidth;
	float m_TextureHeight;

	int m_NumOfRows;
	int m_NumOfColumns;

};

