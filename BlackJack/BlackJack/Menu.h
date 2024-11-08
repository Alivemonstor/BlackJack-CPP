#pragma once
#include <map>
#include <functional>
using namespace std;

class Menu {
public:
	string text;
	function<void> func;
};


void RunMenu(map<int, Menu> & func_list);