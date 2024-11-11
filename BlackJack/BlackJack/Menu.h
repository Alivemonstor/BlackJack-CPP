#pragma once
#include <map>
#include <functional>

class Menu	{
public:
	wchar_t text;
	std::function<void()> func;
};


void RunMenu(std::map<int, Menu>& func_list);
void PrintMainMenu(std::map<int, Menu>& func_list);

