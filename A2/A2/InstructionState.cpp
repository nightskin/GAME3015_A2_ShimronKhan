#include "InstructionState.h"

InstructionState::InstructionState(Game* window) 
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mBg = nullptr;
	mStateType = States::INSTRUCTIONS_STATE;
}

void InstructionState::update(const GameTimer& gt)
{
	if (Active())
	{
		mSceneGraph->update(gt);
		getInputs(gt);
	}
}

void InstructionState::getInputs(const GameTimer& gt)
{
	if (Active())
	{

	}
}

void InstructionState::draw()
{
	if (Active())
	{
		mSceneGraph->draw();
	}
}

void InstructionState::load()
{
	std::unique_ptr<SpriteNode> bg(new SpriteNode(mGame, "Instruction"));
	mBg = bg.get();
	mBg->setPosition(0, 0, 0);
	mBg->setScale(12.0, 1.0, 9.0);
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(bg));
}
