#include "State.h"
#include "Player.h"
#include "Enemy.h"

class GameState : public State
{
public:
	GameState(Game* window);
	void update(const GameTimer& gt) override;
	void getInputs(const GameTimer& gt) override;
	void draw() override;
	void load() override;
private:
	Player* mPlayer;
	SpriteNode* mBackground;
	Enemy* mEnemy;
};