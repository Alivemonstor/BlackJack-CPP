#pragma once
#include <iostream>
#include <vector>
#include "Menu.h"
#include "BlackJack.h"
#include <map>
#include <functional>

Deck pDeck;
Deck hDeck;


void Play() {
    system("cls");
    bool isGame;



    auto stand = []()
    {
        std::wcout << "You have stood" << std::endl;
        Sleep(5000);
        HousePlay();

    };

    Menu option1;
    option1.text = L"Hit";
    option1.func = Hit;
    Menu option2;
    option2.text = L"Stand";
    option2.func = stand;

    std::map<int, Menu> play_list
    {
        {0, option1},
        {1, option2},

    };

    std::wcout << "These are your starter cards: " << std::endl;

    for (size_t i = 0; i < 2; i++) {
        std::pair<std::wstring, int> Card = CardGenerator();
        std::wcout << Card.second << std::endl;
        std::wcout << Card.first << std::endl;
        pDeck.AddCard(Card.first);
        pDeck.UpdateScore(Card.second);
    };

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

    Sleep(5000);

    isGame = true;

    while (isGame) {
        if (pDeck.GetScore() > 21) {
            

            break;
        }
        system("cls");
        RunMenu(play_list, false);
    }
}

void Hit() {
    std::wcout << "You hit";
    std::pair<std::wstring, int> Card = CardGenerator();
    std::wcout << Card.second << std::endl;
    std::wcout << Card.first << std::endl;
    pDeck.AddCard(Card.first);
    pDeck.UpdateScore(Card.second);

    Sleep(5000);

    HousePlay();

}

void HousePlay() {

}

void Quit() {
    return;
}

void RunLoadingScreen() {
    for (int i = 0; i < 15; i++) {
        system("cls");

        std::pair<std::wstring, int> Card = CardGeneratorWithNumber(i);

        std::wcout << Card.first << std::endl;

        Sleep(500);
    }
    system("cls");
    std::wcout << "------------------------------------------------" << std::endl;
    std::wcout << "--------------------- Welcome ------------------" << std::endl;
    std::wcout << "------------------------------------------------" << std::endl;
    std::wcout << std::endl;
    Sleep(1000);
};

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    RunLoadingScreen();

    Menu option1;
	option1.text = L"Play";
	option1.func = Play;
    Menu option2;
    option2.text = L"Quit";
    option2.func = Quit;

    std::map<int, Menu> func_list
    {
        {0, option1},
        {1, option2},

    };

    RunMenu(func_list, true);

}