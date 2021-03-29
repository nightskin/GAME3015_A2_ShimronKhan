#include "TitleState.h"

TitleState::TitleState(Game* window) 
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mBg = nullptr;
	mStateType = States::TITLE_STATE;
}

void TitleState::update(const GameTimer& gt)
{
	if (Active())
	{
		mSceneGraph->update(gt);
		getInputs(gt);
	}
}

void TitleState::getInputs(const GameTimer& gt)
{
	if (Active())
	{

	}
}

void TitleState::draw()
{
	if (Active())
	{
		mSceneGraph->draw();
	}
}

void TitleState::load()
{
	std::unique_ptr<SpriteNode> titleImg(new SpriteNode(mGame, "Title"));
	mBg = titleImg.get();
	mBg->setPosition(0, 0, 0);
	mBg->setScale(15.0, 1.0, 15.0);
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI /180);
	mSceneGraph->attachChild(std::move(titleImg));

	Listener start;
	start.bindChar = ' ';
	start.name = "start";

	listenerManager.AddListener(start);
}

