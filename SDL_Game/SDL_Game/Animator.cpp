#include "Animator.h"
#include "TextureManager.h"
#include "GameTime.h"
#include <iostream>
#include <SDL.h>

Animator::Animator(GameObject* _owner) : Component(_owner)
{
	m_SpritesheetWidth = 0;
	m_SpritesheetHeight = 0;

	m_TotalSpritesheetCols = 1;
	m_TotalSpritesheetRows = 1;

	m_Animation = 1;
	m_Frame = 1;

	m_AnimSpeed = 1.0f;

	m_AnimationTime = 0;
}

Animator::~Animator()
{

}

void Animator::PlayAnimation(float _deltatTime)
{
	m_AnimationTime += _deltatTime * m_AnimSpeed;

	if (m_AnimationTime > 1)
	{
		m_AnimationTime = 0;
		m_Frame = m_Frame >= m_TotalSpritesheetCols ? 1 : m_Frame + 1;
	}
	
	TextureManager::GetInstance()->DrawFrame("Player Run", 250, 250, m_SpritesheetWidth, m_SpritesheetHeight, m_TotalSpritesheetRows, m_TotalSpritesheetCols, m_Animation, m_Frame, SDL_FLIP_NONE, 2);
}

/// <summary>
/// Set start values for the animator
/// </summary>
/// <param name="_width">width of whole spritesheet</param>
/// <param name="_height">height of whole spritesheet</param>
/// <param name="_totalRows">total rows in spritesheet</param>
/// <param name="_totalColumns">total coloumns in spritesheet</param>
/// <param name="_animation">row of animation to play</param>
/// <param name="_frame">column of animation to play</param>
/// <param name="_animSpeed">animation playback speed</param>
void Animator::SetAnimValues(int _width, int _height, int _totalRows, int _totalColumns, int _animation, int _frame, int _animSpeed)
{
	m_SpritesheetWidth = _width;
	m_SpritesheetHeight = _height;

	m_TotalSpritesheetCols = _totalColumns;
	m_TotalSpritesheetRows = _totalRows;

	m_Frame = _frame;
	m_Animation = _animation;

	m_AnimSpeed = _animSpeed;
}
