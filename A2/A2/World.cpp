#include "World.hpp"

World::World(Game* window)
{
	//Important stuff
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mWorldBounds = XMFLOAT4(-1.5f, 1.5f, 200.0f, 0.0f); //Left, Right, Down, Up
	mSpawnPosition = XMFLOAT2(0.f, 0.f);
	mScrollSpeed = 1.0f;
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
		//mTitleState->update(gt);
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->update(gt);
	}
	else if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->update(gt);
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
		//mTitleState->getInputs(gt);
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->getInputs(gt);
	}
	else if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->getInputs(gt);
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
		//mTitleState->draw();
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->draw();
	}
	else if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->draw();
	}
}

void World::load()
{
	
	mTitleState = new TitleState(mGame);
	mMenuState = new MenuState(mGame);
	mInstructionState = new InstructionState(mGame);
	mGameState = new GameState(mGame);
	
	SetState(States::TITLE_STATE);
	
}

void World::SetState(States state)
{
	mCurrentState = state;

	if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->load();
	}
	if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->load();
	}
	if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->load();
	}
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->load();
	}
}

