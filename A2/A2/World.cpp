#include "World.hpp"
#include <iostream>

World::World(Game* window)
{
	//Important stuff
	mGame = window;
	mSceneGraph = new SceneNode(window, "root");
	mWorldBounds = XMFLOAT4(-1.5f, 1.5f, 200.0f, 0.0f); //Left, Right, Down, Up
	mSpawnPosition = XMFLOAT2(0.f, 0.f);
	mScrollSpeed = 1.0f;

	mTitleState = new TitleState(mGame);
	mMenuState = new MenuState(mGame);
	mInstructionState = new InstructionState(mGame);
	mGameState = new GameState(mGame);
	
	mCurrentState = new State();
	mCurrentState->mStateType = States::NONE;

	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
}

void World::update(const GameTimer& gt)
{
	getInputs(gt);
	mSceneGraph->update(gt);
}

void World::getInputs(const GameTimer& gt)
{
	if (mTitleState->mActive)
	{
		if (listenerManager.CheckInput(0x20))
		{
			SetState(mGameState);
		}
	}
}

void World::draw()
{
	mSceneGraph->draw();
}

void World::load()
{
	SetState(mTitleState);
} 

void World::SetState(State* state)
{
	mCurrentState->mActive = false;

	state->mActive = true;
	mCurrentState = state;
	
	if (mCurrentState->mStateType != States::NONE)
	{
		std::unique_ptr<SceneNode> s(new SceneNode(mGame, getCurrentState()));
		mCurrentState->mSceneGraph = s.get();
		mCurrentState->load();
		mSceneGraph->attachChild(std::move(s));
		mSceneGraph->build();
		std::cout << "" << std::endl;
	}
}



std::string World::getCurrentState()
{
	if (mCurrentState->mStateType == States::NONE)
	{
		return "No Current State";
	}
	else
	{
		if (mCurrentState->mStateType == States::TITLE_STATE)
		{
			return "Title State";
		}
		else if (mCurrentState->mStateType == States::MENU_STATE)
		{
			return "Menu State";
		}
		else if (mCurrentState->mStateType == States::INSTRUCTIONS_STATE)
		{
			return "Instruction State";
		}
		else if (mCurrentState->mStateType == States::GAME_STATE)
		{
			return "Game State";
		}
	}
}
