#include "MenuState.h"

MenuState::MenuState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mBg = nullptr;
	mArrow = nullptr;
	option = 0;
}

void MenuState::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	getInputs(gt);
}

void MenuState::getInputs(const GameTimer& gt)
{
	if (listenerManager.CheckInput('W'))
	{
		if (option == 1)
		{
			mArrow->setPosition(-2.0f, -0.75f, 0.0f);
			option = 0;
		}
	}
	else if (listenerManager.CheckInput('S'))
	{
		if (option  == 0)
		{
			mArrow->setPosition(-3.0f, -2.75f, 0.0f);
			option = 1;
		}
	}
}

void MenuState::draw()
{
	mSceneGraph->draw();
}

void MenuState::load()
{
	std::unique_ptr<SpriteNode> bg(new SpriteNode(mGame, "Menu"));
	mBg = bg.get();
	mBg->setPosition(0, 0, 1);
	mBg->setScale(15.0, 1.0, 15.0);
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(bg));


	std::unique_ptr<SpriteNode> arrow(new SpriteNode(mGame, "Selector"));
	mArrow = arrow.get();
	mArrow->setPosition(-2.0f, -0.75f, 0.0f);
	mArrow->setScale(1.0, 1.0, 1.0);
	mArrow->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(arrow));

	Listener up;
	up.key = 'W';
	up.name = "ToggleUP";
	Listener down;
	down.key = 'S';
	down.name = "ToggleDOWN";

	listenerManager.AddListener(up);
	listenerManager.AddListener(down);

	mSceneGraph->build();
}
