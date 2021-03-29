#pragma once
#include "State.h"

class TitleState : public State
{
public:
	TitleState(Game* window);
	void update(const GameTimer& gt) override;
	void getInputs(const GameTimer& gt) override;
	void draw() override;
	void load() override;
public:
	SpriteNode* mBg;
};
