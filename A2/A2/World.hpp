#pragma once
#include "World.hpp"
#include "TitleState.h"
#include "MenuState.h"
#include "GameState.h"
#include "InstructionState.h"

#include "StateList.h"

class World 
{
public:
	explicit World(Game* window);
	void update(const GameTimer& gt);
	void getInputs(const GameTimer& gt);
	void draw();
	void load();
	void SetState(State* stste);
private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};
private:
	Game* mGame;
	State* mCurrentState;

	SceneNode* mSceneGraph;
	GameState* mGameState;
	TitleState* mTitleState;
	MenuState* mMenuState;
	InstructionState* mInstructionState;

	std::array<SceneNode*, LayerCount> mSceneLayers;
	ListenerManager listenerManager;
	XMFLOAT4 mWorldBounds;
	XMFLOAT2 mSpawnPosition;
	float mScrollSpeed;
};
