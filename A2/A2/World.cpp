#include "World.hpp"

World::World(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mGameState = new GameState(window);
	

	mWorldBounds = XMFLOAT4(-1.5f, 1.5f, 200.0f, 0.0f); //Left, Right, Down, Up
	mSpawnPosition  = XMFLOAT2(0.f, 0.f);
	mScrollSpeed = 1.0f;
}

void World::update(const GameTimer& gt)
{
	mGameState->update(gt);
	getInputs(gt);
}

void World::getInputs(const GameTimer& gt)
{
	mGameState->getInputs(gt);
}

void World::draw()
{
	mGameState->draw();
}

void World::load()
{
	mGameState->load();
}

