
#include <iostream>
#include <vector>
#include "Menu.h"
#include "BlackJack.h"
#include <map>
#include <functional>

using namespace std;

void Test() {
    cout << "hello";
}

int main()
{
	Menu option1;
	option1.text = "Test";
	option1.func = Test;
    map<int, Menu> func_list
    {
        {0, option1}
    };
    RunMenu(func_list);

    return 0;
}