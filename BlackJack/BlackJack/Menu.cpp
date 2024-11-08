#include <iostream>
#include <vector>
#include "Menu.h"
#include <Windows.h>
#include "BlackJack.h"
#include <map>
#include <functional>
#include <sstream>
#include <algorithm>

using namespace std;


void RunMenu(map<int, Menu&> func_list)
{
    int menuSelect = 0;

    bool previousKeyState = false;
    bool selected = false; 

	stringstream selection; 

    while (!selected) 
    {
        int UpKeyState = GetAsyncKeyState(VK_UP);
        int DownKeyState = GetAsyncKeyState(VK_DOWN);
        int ReturnState = GetAsyncKeyState(VK_RETURN);

        if (UpKeyState < 0 || DownKeyState < 0 || ReturnState < 0)
        {
			cout << menuSelect << endl;

            if (previousKeyState)
            {
                continue;
            }

            if (!previousKeyState)
            {
                if (UpKeyState)
                {
                    menuSelect++;
                }
                else if (DownKeyState)
                {
                    menuSelect--;
                }
                else if (ReturnState)
                {
                    func_list[menuSelect].func();
                    selected = true;
                }

                cout << menuSelect;

                previousKeyState = true;

                if (menuSelect > func_list.size()+1 || menuSelect < 1) {
                    menuSelect = 0;
                }
            }
        }
        else
        {
            previousKeyState = false;
        }
    };
}