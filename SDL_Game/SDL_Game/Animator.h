#pragma once
#include "Component.h"

class Animator : public Component
{
public:
	Animator();
	~Animator();

	void PlayAnimation();

private:
	int m_TotalFrames;
	int m_AnimationRow;
	int m_FrameColumn;

	float m_AnimSpeed;
	
};

