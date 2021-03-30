#include "GameState.h"


GameState::GameState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Game State");
	mPlayer = nullptr;
	mBackground = nullptr;
	mEnemy1 = nullptr;
	mEnemy2 = nullptr;
	mStateType = States::GAME_STATE;
	mActive = false;
}

void GameState::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	getInputs(gt);
}

void GameState::getInputs(const GameTimer& gt)
{
	mPlayer->input(gt);
}

void GameState::draw()
{
	mSceneGraph->draw();
}

void GameState::load()
{
	std::unique_ptr<Player> player(new Player(mGame, "Player"));
	mPlayer = player.get();
	mPlayer->setPosition(0, -3, 0);
	mPlayer->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mPlayer->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Enemy> enemy1(new Enemy(mGame, "Enemy 1"));
	mEnemy1 = enemy1.get();
	mEnemy1->setPosition(0.5, 3.0f, 0);
	mEnemy1->setWorldRotation(90 * XM_PI / 180, 0, 0);
	mEnemy1->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(enemy1));

	std::unique_ptr<Enemy> enemy2(new Enemy(mGame, "Enemy 2"));
	mEnemy2 = enemy2.get();
	mEnemy2->setPosition(-0.5, 3.0f, 0);
	mEnemy2->setWorldRotation(90 * XM_PI / 180, 0, 0);
	mEnemy2->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame, "Desert", "Bg"));
	mBackground = backgroundSprite.get();
	mBackground->setPosition(0, 0, 0);
	mBackground->setScale(15.0, 1.0, 100.0);
	mBackground->setWorldRotation(90 * XM_PI / 180, 0, 0);
	mBackground->setVelocity(0, -2);
	mSceneGraph->attachChild(std::move(backgroundSprite));
}
