#include "World.hpp"

World::World(Game* window)
{
	//Important stuff
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mWorldBounds = XMFLOAT4(-1.5f, 1.5f, 200.0f, 0.0f); //Left, Right, Down, Up
	mSpawnPosition = XMFLOAT2(0.f, 0.f);
	mScrollSpeed = 1.0f;

	mTitleState = new TitleState(mGame);
	mMenuState = new MenuState(mGame);
	mInstructionState = new InstructionState(mGame);
	mGameState = new GameState(mGame);
	mCurrentState = new State();
}

void World::update(const GameTimer& gt)
{
	getInputs(gt);
	if (mCurrentState->mStateType == States::TITLE_STATE)
	{
		mTitleState->update(gt);
	}
	if (mCurrentState->mStateType == States::MENU_STATE)
	{
		mMenuState->update(gt);
	}
	if (mCurrentState->mStateType == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->update(gt);
	}
	if (mCurrentState->mStateType == States::GAME_STATE)
	{
		mGameState->update(gt);
	}
}

void World::getInputs(const GameTimer& gt)
{
	if (mCurrentState->mStateType == States::TITLE_STATE)
	{
		mTitleState->getInputs(gt);
	}
	if (mCurrentState->mStateType == States::MENU_STATE)
	{
		mMenuState->getInputs(gt);
	}
	if (mCurrentState->mStateType == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->getInputs(gt);
	}
	if (mCurrentState->mStateType == States::GAME_STATE)
	{
		mGameState->getInputs(gt);
	}

}

void World::draw()
{
	if (mCurrentState->mStateType == States::TITLE_STATE)
	{
		mTitleState->draw();
	}
	if (mCurrentState->mStateType == States::MENU_STATE)
	{
		mMenuState->draw();
	}
	if (mCurrentState->mStateType == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->draw();
	}
	if (mCurrentState->mStateType == States::GAME_STATE)
	{
		mGameState->draw();
	}
}

void World::load()
{	
	SetState(mGameState);
}

void World::SetState(State* state)
{
	//Deactivate prev state
	
	//Set new State
	mCurrentState = state;
	//Activate new State
	std::unique_ptr<SceneNode> s (new SceneNode(mGame));
	mCurrentState->mSceneGraph = s.get();
	mCurrentState->setActive(true);
	mCurrentState->load();
	mSceneGraph->attachChild(std::move(s));
	mSceneGraph->build();
}