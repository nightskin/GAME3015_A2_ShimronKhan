#pragma once
#include <vector>
#include <string>


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