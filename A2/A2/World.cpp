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
	mCurrentState->mStateType = States::NONE;
	

}

void World::update(const GameTimer& gt)
{
	getInputs(gt);
	mCurrentState->update(gt);
}

void World::getInputs(const GameTimer& gt)
{
	mCurrentState->getInputs(gt);
}

void World::draw()
{
	mCurrentState->draw();
}

void World::load()
{	
	SetState(mTitleState);
	mSceneGraph->build();
}

void World::SetState(State* state)
{
	//Deactivate state
	if (mCurrentState->mStateType != States::NONE)
	{
		mSceneGraph->detachChild(*mCurrentState->mSceneGraph);
	}
	
	//Set new State
	mCurrentState = state;
	
	//Activate new State
	std::unique_ptr<SceneNode> s (new SceneNode(mGame));
	mCurrentState->mSceneGraph = s.get();
	mCurrentState->load();
	mSceneGraph->attachChild(std::move(s));	
}