#include "InstructionState.h"

InstructionState::InstructionState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mBg = nullptr;
}

void InstructionState::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	getInputs(gt);

}

void InstructionState::getInputs(const GameTimer& gt)
{
}

void InstructionState::draw()
{
	mSceneGraph->draw();
}

void InstructionState::load()
{
	std::unique_ptr<SpriteNode> bg(new SpriteNode(mGame, "Instruction"));
	mBg = bg.get();
	mBg->setPosition(0, 0, 1);
	mBg->setScale(15.0, 1.0, 10.0);
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(bg));

	//mSceneGraph->build();
}
