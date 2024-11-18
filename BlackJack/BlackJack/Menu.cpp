#pragma once
#include <iostream>
#include "Menu.h"
#include <Windows.h>
#include "BlackJack.h"
#include <map>
#include <functional>
#include <algorithm>

int menuSelect = 1;


void RunMenu(std::map<int, Menu>& func_list)
{
    bool previousKeyState = false;
    bool selected = false; 
    PrintMainMenu(func_list);



    while (!selected) 
    {
        int UpKeyState = GetAsyncKeyState(VK_UP);
        int DownKeyState = GetAsyncKeyState(VK_DOWN);
        int ReturnState = GetAsyncKeyState(VK_RETURN);

        if (UpKeyState < 0 || DownKeyState < 0 || ReturnState < 0)
        {

            if (previousKeyState)
            {
                continue;
            }

            if (!previousKeyState)
            {
                if (UpKeyState)
                {
                    menuSelect--;
                }
                else if (DownKeyState)
                {
                    menuSelect++;
                }
                else if (ReturnState)
                {
                    func_list[menuSelect-1].func();
                    selected = true;
                    break;
                }


                previousKeyState = true;

                if (menuSelect > func_list.size() || menuSelect < 1) {
                    menuSelect = 1;
                }
                PrintMainMenu(func_list);
            }
        }
        else
        {
            previousKeyState = false;
        }
    };
}

void PrintMainMenu(std::map<int, Menu>& func_list)
{
    system("cls");
    std::wcout << "------------------------------------------------" << std::endl;
    std::wcout << "--------------------- MENU ---------------------" << std::endl;
    std::wcout << "------------------------------------------------" << std::endl;
    std::wcout << std::endl;
    std::wcout << "Select an option using arrow keys" << std::endl;

    for (int i = 0; i < func_list.size(); i++) {
        if (i == menuSelect-1) {
            std::wcout << L"> " << func_list[i].text << std::endl;
        }
        else {
            std::wcout << func_list[i].text << std::endl;
        }
    }
}