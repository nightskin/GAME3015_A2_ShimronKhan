#pragma once
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Input.h"

class MenuState
{
public:
	MenuState(Game* window);
	void update(const GameTimer& gt);
	void getInputs(const GameTimer& gt);
	void draw();
	void load();
private:
	SceneNode* mSceneGraph;
private:
	Game* mGame;
	ListenerManager	listenerManager;
	SpriteNode* mBg;
	SpriteNode* mArrow;
	int option;
};
