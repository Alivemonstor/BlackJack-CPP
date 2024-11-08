#include <iostream>
#include <vector>
#include "Menu.h"
#include <Windows.h>
#include "BlackJack.h"
#include <map>
#include <functional>
#include <string>
using namespace std;


void RunMenu(map<int, function<void()>>& func_list)
{
    int menuSelect = 1;
    bool previousKeyState = false;
    bool selected = false; 

    while (!selected) {

        if (GetAsyncKeyState(VK_UP) < 0 or GetAsyncKeyState(VK_DOWN) < 0 or GetAsyncKeyState(VK_RETURN) < 0)
        {
            if (!previousKeyState)
            {
                if (GetAsyncKeyState(VK_UP)) {
                    menuSelect += 1;
                    cout << menuSelect;

                }
                else if (GetAsyncKeyState(VK_DOWN)) 
                {
                    menuSelect -= 1;
                    cout << menuSelect;
                }
                else if (GetAsyncKeyState(VK_RETURN))
                {
                    func_list[menuSelect]();
                    selected = true;
                }
                previousKeyState = true;
            }
        }
        else
        {
            previousKeyState = false;
        }
        if (menuSelect > func_list.size() or menuSelect < 1) {
            menuSelect = 1;
        }
    };
}