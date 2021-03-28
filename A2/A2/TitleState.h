#pragma once
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Input.h"


class TitleState
{
public:
	TitleState(Game* window);
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
};
