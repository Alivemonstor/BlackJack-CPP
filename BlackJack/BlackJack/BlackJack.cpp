#pragma once
#include <iostream>
#include <vector>
#include "Menu.h"
#include "BlackJack.h"
#include <map>
#include <functional>




void Play() {
    std::wstring Card = CardGenerator();
}

void Leaderboard() {
    std::cout << "hello";
}

void Quit() {
    return;
}
    
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    Menu option1;
	option1.text = L"Play";
	option1.func = Play;
    Menu option2;
    option2.text = L"Leaderboard";
    option2.func = Leaderboard;
    Menu option3;
    option3.text = L"Quit";
    option3.func = Quit;

    std::map<int, Menu> func_list
    {
        {0, option1},
        {1, option2},
        {2, option3},

    };

    RunMenu(func_list);

    return 0;
}