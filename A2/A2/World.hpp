#pragma once
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "World.hpp"
#include "Player.h"
#include "Enemy.h"

struct Listener
{
	char key;
	std::string name;
};

class ListenerManager
{
public:
	ListenerManager();
	~ListenerManager();
	bool CheckInput(char key);
	Listener PrevEvent();
	Listener CurrentEvent();
	void AddListener(Listener ev);
	void RemoveListener(std::string evName);
private:
	std::vector<Listener> listeners;
	std::vector<Listener> eventList;
};

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
