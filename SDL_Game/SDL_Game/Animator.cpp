#include "Animator.h"

Animator::Animator() : Component(m_Owner)
{
	m_AnimSpeed = 1.0f;
	m_AnimationRow = 0;
	m_FrameColumn = 0;
	m_TotalFrames = 0;
}

Animator::~Animator()
{

}

void Animator::PlayAnimation()
{
}
