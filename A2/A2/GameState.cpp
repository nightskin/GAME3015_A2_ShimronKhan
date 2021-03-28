#include "GameState.h"


GameState::GameState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window);
	mState = States::GAME_STATE;
}

void GameState::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	getInputs(gt);
}

void GameState::getInputs(const GameTimer& gt)
{
	float speed = 2.0f * gt.DeltaTime();

	if (listenerManager.CheckInput('D'))
	{
		mPlayer->move(speed, 0, 0);
	}

	if (listenerManager.CheckInput('A'))
	{
		mPlayer->move(-speed, 0, 0);
	}
}

void GameState::draw()
{
	mSceneGraph->draw();
}

void GameState::load()
{
	std::unique_ptr<Player> player(new Player(mGame));
	mPlayer = player.get();
	mPlayer->setPosition(0, -3, 0);
	mPlayer->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mPlayer->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Enemy> enemy1(new Enemy(mGame));
	auto raptor = enemy1.get();
	raptor->setPosition(0.5, 3, 0);
	raptor->setWorldRotation(90 * XM_PI / 180, 0, 0);
	raptor->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(enemy1));

	std::unique_ptr<Enemy> enemy2(new Enemy(mGame));
	auto raptor2 = enemy2.get();
	raptor2->setPosition(-0.5, 3, 0);
	raptor2->setWorldRotation(90 * XM_PI / 180, 0, 0);
	raptor->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame));
	mBackground = backgroundSprite.get();
	mBackground->setPosition(0, 0, 1);
	mBackground->setScale(10.0, 1.0, 200.0);
	mBackground->setWorldRotation(90 * XM_PI / 180, 0, 0);
	mBackground->setVelocity(0, -2);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	mSceneGraph->build();

	//Create Listeners
	Listener aKey;
	aKey.key = 'A';
	aKey.name = "AKey";
	Listener dKey;
	dKey.key = 'D';
	dKey.name = "DKey";
	// Add listeners to listener manager
	listenerManager.AddListener(aKey);
	listenerManager.AddListener(dKey);
}
