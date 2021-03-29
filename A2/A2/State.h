#pragma once
#include "Input.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"

class State
{
public:
	State(Game* window);
	~State();
	virtual void update(const GameTimer& gt);
	virtual void getInputs(const GameTimer& gt);
	virtual void draw();
	virtual void load();
	void setActive(bool tf);
	bool Active();
public:
	SceneNode* mWorld;
	SceneNode* mSceneGraph;
	ListenerManager	listenerManager;
	Game* mGame;
private:
	bool active;
};
