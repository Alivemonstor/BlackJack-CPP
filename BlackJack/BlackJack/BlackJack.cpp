
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
    cout << "Hi";
    Menu Obj1;
    vector<Menu> MenuList;


    map<int, Menu> func_list{
        {0, Obj1}
    };
    RunMenu(func_list);

    return 0;
}