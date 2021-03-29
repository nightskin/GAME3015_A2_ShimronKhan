#include "World.hpp"

World::World(Game* window)
{
	//Important stuff
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mWorldBounds = XMFLOAT4(-1.5f, 1.5f, 200.0f, 0.0f); //Left, Right, Down, Up
	mSpawnPosition = XMFLOAT2(0.f, 0.f);
	mScrollSpeed = 1.0f;
	mTitleState = nullptr;
	mMenuState = nullptr;
	mInstructionState = nullptr;
	mGameState = nullptr;
}

void World::update(const GameTimer& gt)
{
	getInputs(gt);
	if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->update(gt);
	}
	if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->update(gt);
	}
	if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->update(gt);
	}
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->update(gt);
	}
}

void World::getInputs(const GameTimer& gt)
{
	if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->getInputs(gt);
	}
	if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->getInputs(gt);
	}
	if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->getInputs(gt);
	}
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->getInputs(gt);
	}

}

void World::draw()
{
	if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState->draw();
	}
	if (mCurrentState == States::MENU_STATE)
	{
		mMenuState->draw();
	}
	if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState->draw();
	}
	if (mCurrentState == States::GAME_STATE)
	{
		mGameState->draw();
	}
}

void World::load()
{	
	SetState(States::TITLE_STATE);
	mSceneGraph->build();
}

void World::SetState(States state)
{
	if (mCurrentState == States::TITLE_STATE)
	{
		mTitleState = new TitleState(mGame);
		mTitleState->mWorld = mSceneGraph;
		std::unique_ptr<SceneNode> title(new SceneNode(mGame));
		mTitleState->mSceneGraph = title.get();
		mTitleState->setActive(true);
		mTitleState->load();
		mSceneGraph->attachChild(std::move(title));
	}
	else if (mCurrentState == States::MENU_STATE)
	{
		mMenuState = new MenuState(mGame);
		mMenuState->mWorld = mSceneGraph;
		std::unique_ptr<SceneNode> menu(new SceneNode(mGame));
		mMenuState->mSceneGraph = menu.get();
		mMenuState->setActive(true);
		mMenuState->load();
		mSceneGraph->attachChild(std::move(menu));
	}
	else if (mCurrentState == States::INSTRUCTIONS_STATE)
	{
		mInstructionState = new InstructionState(mGame);
		mInstructionState->mWorld = mSceneGraph;
		std::unique_ptr<SceneNode> instruct(new SceneNode(mGame));
		mInstructionState->mSceneGraph = instruct.get();
		mInstructionState->setActive(true);
		mInstructionState->load();
		mSceneGraph->attachChild(std::move(instruct));
	}
	else if (mCurrentState == States::GAME_STATE)
	{
		mGameState = new GameState(mGame);
		mGameState->mWorld = mSceneGraph;
		std::unique_ptr<SceneNode> game(new SceneNode(mGame));
		mGameState->mSceneGraph = game.get();
		mGameState->setActive(true);
		mGameState->load();
		mSceneGraph->attachChild(std::move(game));
	}
}