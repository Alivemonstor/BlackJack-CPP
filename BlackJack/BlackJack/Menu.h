#pragma once
#include <map>
#include <functional>

class Menu	{
public:
	const wchar_t* text;
	std::function<void()> func;
};


void RunMenu(std::map<int, Menu>& func_list, bool isMainMenu);
void PrintMainMenu(std::map<int, Menu>& func_list, bool isMainMenu);

