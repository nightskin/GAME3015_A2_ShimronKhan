#include "World.hpp"

World::World(Game* game)
	: mSceneGraph(new SceneNode(game))
	, mGame(game)
	, mPlayerAircraft(nullptr)
	, mBackground(nullptr)
	, mWorldBounds(-1.5f, 1.5f, 200.0f, 0.0f) //Left, Right, Down, Up
	, mSpawnPosition(0.f, 0.f)
	, mScrollSpeed(1.0f)
{
}

void World::update(const GameTimer& gt)
{
	mSceneGraph->update(gt);
	GetInputs(gt);
}

void World::GetInputs(const GameTimer& gt)
{
	float speed = 2.0f * gt.DeltaTime();

	if (listenerManager.CheckInput('D'))
	{
		mPlayerAircraft->move(speed, 0, 0);
	}
	
	if (listenerManager.CheckInput('A'))
	{
		mPlayerAircraft->move(-speed, 0, 0);
	}
}

void World::draw()
{
	mSceneGraph->draw();
}

void World::load()
{
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, mGame));
	mPlayerAircraft = player.get();
	mPlayerAircraft->setPosition(0, 0.1, 0.0);
	mPlayerAircraft->setScale(0.5, 0.5, 0.5);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Aircraft> enemy1(new Aircraft(Aircraft::Raptor, mGame));
	auto raptor = enemy1.get();
	raptor->setPosition(0.5, 0, 1);
	raptor->setScale(0.5f, 0.5f, 0.5f);
	raptor->setWorldRotation(0, XM_PI, 0);
	mSceneGraph->attachChild(std::move(enemy1));

	std::unique_ptr<Aircraft> enemy2(new Aircraft(Aircraft::Raptor, mGame));
	auto raptor2 = enemy2.get();
	raptor2->setPosition(-0.5, 0, 1);
	raptor->setScale(0.5f, 0.5f, 0.5f);
	raptor2->setWorldRotation(0, XM_PI, 0);
	mSceneGraph->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame));
	mBackground = backgroundSprite.get();
	mBackground->setPosition(0, 0, 0.0);
	mBackground->setScale(10.0, 1.0, 200.0);
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

ListenerManager::ListenerManager()
{

}

ListenerManager::~ListenerManager()
{

}

bool ListenerManager::CheckInput(char key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		for (int i = 0; i < listeners.size(); i++)
		{
			if (listeners[i].key == key)
			{
				eventList.push_back(listeners[i]);
			}
		}
		return true;
	}
	return false;
}

Listener ListenerManager::PrevEvent()
{
	if (eventList.size() > 1)
	{
		return eventList[eventList.size() - 2];
	}
}

Listener ListenerManager::CurrentEvent()
{
	if (eventList.size() > 0)
	{
		if (CheckInput(eventList[eventList.size() - 1].key))
		{
			return eventList[eventList.size() - 1];
		}
	}
}

void ListenerManager::AddListener(Listener ev)
{
	listeners.push_back(ev);
}

void ListenerManager::RemoveListener(std::string evName)
{
	for (int i = 0; i < listeners.size(); i++)
	{
		if (listeners[i].name == evName)
		{
			listeners.erase(listeners.begin() + i);
		}
	}
}
