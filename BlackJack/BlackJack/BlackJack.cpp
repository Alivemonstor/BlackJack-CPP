#pragma once
#include <iostream>
#include <vector>
#include "Menu.h"
#include "BlackJack.h"
#include <map>
#include <functional>


void Play() {
    std::string Card = CardGenerator();
    std::cout << Card;

}

void Leaderboard() {
    std::cout << "hello";
}

void Quit() {
    return;
}
    
int main()
{
	Menu option1;
	option1.text = "Play";
	option1.func = Play;
    Menu option2;
    option2.text = "Leaderboard";
    option2.func = Leaderboard;
    Menu option3;
    option3.text = "Quit";
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