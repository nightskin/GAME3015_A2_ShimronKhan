#pragma once
#include <vector>
#include <string>


struct Listener
{
	char bindChar;
	int bindInt;
	std::string name;
};

class ListenerManager
{
public:
	ListenerManager();
	~ListenerManager();
	bool CheckInput(char key);
	bool CheckInput(int key);
	bool CheckListener(Listener ev);
	Listener PrevEvent();
	Listener CurrentEvent();
	void AddListener(Listener ev);
	void RemoveListener(std::string evName);
private:
	std::vector<Listener> listeners;
	std::vector<Listener> eventList;
};