#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Player.h"
#include "Enemy.h"

class GameState
{
public:
	GameState(Game* window);
	void update(const GameTimer& gt);
	void getInputs(const GameTimer& gt);
	void draw();
	void load();
public:
	SceneNode* mSceneGraph;
private:
	ListenerManager	listenerManager;
	Game* mGame;
	Player* mPlayer;
	SpriteNode* mBackground;
	Enemy* mEnemy;
};