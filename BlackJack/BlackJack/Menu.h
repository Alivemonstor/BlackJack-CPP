#pragma once
#include <map>
#include <functional>

class Menu	{
public:
	std::string text;
	std::function<void()> func;
};


void RunMenu(std::map<int, Menu>& func_list);
void PrintMainMenu(std::map<int, Menu>& func_list);

