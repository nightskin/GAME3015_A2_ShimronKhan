#include "States.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Player.h"
#include "Enemy.h"
#include "Input.h"
#include "States.h"

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
	States mState;
private:
	ListenerManager	listenerManager;
	Game* mGame;
	Player* mPlayer;
	SpriteNode* mBackground;
	Enemy* mEnemy;
};