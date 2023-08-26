#pragma once
#include "Component.h"

class Animator : public Component
{
public:
	Animator(GameObject* _owner);
	~Animator();

	void PlayAnimation(float _deltaTime);

	void SetAnimValues(int _width, int _height, int _totalRows, int _totalColumns, int _animation, int _frame, int _animSpeed);

	inline void SetAnimSpeed(float _speed) { m_AnimSpeed = _speed; }
	inline void SetAnimation(int _row) { m_Animation = _row; }
	inline void SetFrame(int _column) { m_Frame = _column; }



private:
	int m_SpritesheetWidth;
	int m_SpritesheetHeight;

	int m_TotalSpritesheetCols;
	int m_TotalSpritesheetRows;

	int m_Animation;
	int m_Frame;

	float m_AnimSpeed;
	float m_AnimationTime;
	
};

