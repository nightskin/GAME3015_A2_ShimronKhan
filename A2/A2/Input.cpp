#include "Input.h"
#include "Game.hpp"

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


