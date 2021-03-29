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
		mTitleState->update(gt);
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
		mTitleState->getInputs(gt);
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
		mTitleState->draw();
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
	mTitleState->mWorld = mSceneGraph;
	mMenuState = new MenuState(mGame);
	mMenuState->mWorld = mSceneGraph;
	mInstructionState = new InstructionState(mGame);
	mInstructionState->mWorld = mSceneGraph;
	mGameState = new GameState(mGame);
	mGameState->mWorld = mSceneGraph;


	std::unique_ptr<SceneNode> title(new SceneNode(mGame));
	mTitleState->mSceneGraph = title.get();
	mTitleState->load();
	mSceneGraph->attachChild(std::move(title));

	std::unique_ptr<SceneNode> menu(new SceneNode(mGame));
	mMenuState->mSceneGraph = menu.get();
	mMenuState->load();
	mSceneGraph->attachChild(std::move(menu));

	std::unique_ptr<SceneNode> instruct(new SceneNode(mGame));
	mInstructionState->mSceneGraph = instruct.get();
	mInstructionState->load();
	mSceneGraph->attachChild(std::move(instruct));

	std::unique_ptr<SceneNode> game(new SceneNode(mGame));
	mGameState->mSceneGraph = game.get();
	mGameState->load();
	mSceneGraph->attachChild(std::move(game));

	SetState(States::MENU_STATE);
	mSceneGraph->build();
}

void World::SetState(States state)
{
	mCurrentState = state;

	if (mCurrentState == States::TITLE_STATE)
	{
		
	}
	if (mCurrentState == States::MENU_STATE)
	{
		
	}
	if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		
	}
	if (mCurrentState == States::GAME_STATE)
	{
		
	}
}