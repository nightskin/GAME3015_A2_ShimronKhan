#include "World.hpp"

World::World(Game* window)
{
	//Important stuff
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mWorldBounds = XMFLOAT4(-1.5f, 1.5f, 200.0f, 0.0f); //Left, Right, Down, Up
	mSpawnPosition = XMFLOAT2(0.f, 0.f);
	mScrollSpeed = 1.0f;
	// States
	mGameState = new GameState(window);
	mTitleState = new TitleState(window);
	mMenuState = new MenuState(window);

	//start state
	mCurrentState = States::MENU_STATE;
}

void World::update(const GameTimer& gt)
{
	getInputs(gt);
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->update(gt);
	}
	else if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->update(gt);
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->update(gt);
	}
	else if (mCurrentState == States::PAUSE_STATE)
	{

	}
}

void World::getInputs(const GameTimer& gt)
{
	
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->getInputs(gt);
	}
	else if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->getInputs(gt);
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->getInputs(gt);
	}
	else if (mCurrentState == States::PAUSE_STATE)
	{

	}
}

void World::draw()
{
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->draw();
	}
	else if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->draw();
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->draw();
	}
	else if (mCurrentState == States::PAUSE_STATE)
	{

	}
}

void World::load()
{
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->load();
	}
	else if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->load();
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->load();
	}
	else if (mCurrentState == States::PAUSE_STATE)
	{

	}
}

