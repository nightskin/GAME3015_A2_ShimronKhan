#pragma once
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "World.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Input.h"



class World 
{
public:
	explicit World(Game* window);
	void update(const GameTimer& gt);
	void GetInputs(const GameTimer& gt);
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
	Game*								mGame;
	SceneNode*							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	ListenerManager						listenerManager;
	XMFLOAT4							mWorldBounds;
	XMFLOAT2		    				mSpawnPosition;
	float								mScrollSpeed;
	Player*								mPlayer;
	SpriteNode*							mBackground;
	Enemy*								mEnemy;
};
