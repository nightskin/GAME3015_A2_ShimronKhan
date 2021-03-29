#include "State.h"

State::State(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
}

State::~State()
{

}

void State::update(const GameTimer& gt)
{

}

void State::getInputs(const GameTimer& gt)
{

}

void State::draw()
{

}

void State::load()
{

}

void State::setActive(bool tf)
{
	active = tf;
}

bool State::Active()
{
	return active;
}
