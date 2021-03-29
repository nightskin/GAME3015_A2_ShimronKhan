#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState(Game* window);
	void update(const GameTimer& gt) override;
	void getInputs(const GameTimer& gt) override;
	void draw() override;
	void load() override;
public:
	SceneNode* mWorld;
	SceneNode* mSceneGraph;
private:
	Game* mGame;
	ListenerManager	listenerManager;
	SpriteNode* mBg;
	SpriteNode* mArrow;
	int option;
};
