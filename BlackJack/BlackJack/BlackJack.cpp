
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
    map<int, function<void()>> func_list{
        {0, Test}
    };
    RunMenu(func_list);

    return 0;
}