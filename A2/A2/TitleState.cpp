#include "TitleState.h"

TitleState::TitleState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mTitleImg = nullptr;
}

void TitleState::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	getInputs(gt);
}

void TitleState::getInputs(const GameTimer& gt)
{

}

void TitleState::draw()
{
	mSceneGraph->draw();
}

void TitleState::load()
{

	std::unique_ptr<SpriteNode> titleImg(new SpriteNode(mGame, "Title"));
	mTitleImg = titleImg.get();
	mTitleImg->setPosition(0, 0, 0);
	mTitleImg->setScale(15.0, 1.0, 15.0);
	mTitleImg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI /180);
	mSceneGraph->attachChild(std::move(titleImg));

	mSceneGraph->build();
}