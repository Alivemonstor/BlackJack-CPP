#pragma once
#include <map>
#include <functional>
using namespace std;

void RunMenu(map<int, function<void()>>& func_list);