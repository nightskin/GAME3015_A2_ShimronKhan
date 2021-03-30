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
	std::cout << getCurrentState() << std::endl;
	state->mActive = true;
	mCurrentState = state;
	
	if (mCurrentState->mStateType != States::NONE)
	{
		std::unique_ptr<SceneNode> s(new SceneNode(mGame, getCurrentState()));
		mCurrentState->mSceneGraph = s.get();
		mCurrentState->load();
		mSceneGraph->attachChild(std::move(s));
		mSceneGraph->build();
		std::cout << getCurrentState() << std::endl;
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
			if (mCurrentState->mActive)
			{
				return "Title State Active";
			}
			else
			{
				return "Title State Not Active";
			}
		}
		else if (mCurrentState->mStateType == States::MENU_STATE)
		{
			if (mCurrentState->mActive)
			{
				return "Menu State Active";
			}
			else
			{
				return "Menu State Not Active";
			}
		}
		else if (mCurrentState->mStateType == States::INSTRUCTIONS_STATE)
		{
			if (mCurrentState->mActive)
			{
				return "Instructions State Active";
			}
			else
			{
				return "Instructions State Not Active";
			}
		}
		else if (mCurrentState->mStateType == States::GAME_STATE)
		{
			if (mCurrentState->mActive)
			{
				return "Game State Active";
			}
			else
			{
				return "Game State Not Active";
			}
		}
	}
}
