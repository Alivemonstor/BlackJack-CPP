#pragma once
#include <iostream>
#include <vector>
#include "Menu.h"
#include "BlackJack.h"
#include <map>
#include <functional>




void Play() {
    system("cls");
    Deck pDeck;
    Deck hDeck;

    std::wcout << "These are your starter cards: " << std::endl;

    for (size_t i = 0; i < 2; i++) {
        std::pair<std::wstring, int> Card = CardGenerator();
        std::wcout << Card.second << std::endl;
        std::wcout << Card.first << std::endl;
        pDeck.AddCard(Card.first);
        pDeck.UpdateScore(Card.second);
    };

    std::wcout << pDeck.TotalScore;
    Sleep(5000);

    system("cls");

    std::wcout << "These are the houses' starter cards: " << std::endl;

    for (size_t i = 0; i < 2; i++) {

        switch (i)
        {
        case 0:
        {

            std::pair<std::wstring, int> Card = CardGenerator();
            std::wcout << Card.second << std::endl;
            std::wcout << Card.first << std::endl;
            hDeck.AddCard(Card.first);
            hDeck.UpdateScore(Card.second);
            break;
        }
        case 1:
        {
            std::pair<std::wstring, int> Hidden = GenerateHidden();
            std::wcout << Hidden.second << std::endl;
            std::wcout << Hidden.first << std::endl;
            hDeck.AddCard(Hidden.first);
            hDeck.UpdateScore(Hidden.second);
            break;
        }
        }
    };
    std::wcout << hDeck.TotalScore;


}

void Leaderboard() {
    std::cout << "hello";
}

void Quit() {
    return;
}
    

void Ask() {
    
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