#include "State.h"


void State::update(const GameTimer& gt)
{

}

void State::getInputs(const GameTimer& gt)
{
}

void State::draw()
{
	mSceneGraph->build();
	mSceneGraph->draw();
}

void State::load()
{
}


