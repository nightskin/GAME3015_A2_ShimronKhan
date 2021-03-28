#pragma once
#include "World.hpp"
#include "GameState.h"

class World 
{
public:
	explicit World(Game* window);
	void update(const GameTimer& gt);
	void getInputs(const GameTimer& gt);
	void draw();
	void load();

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};
private:
	Game* mGame;
	SceneNode* mSceneGraph;
	GameState* mGameState;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	ListenerManager listenerManager;
	XMFLOAT4 mWorldBounds;
	XMFLOAT2 mSpawnPosition;
	float mScrollSpeed;
};
