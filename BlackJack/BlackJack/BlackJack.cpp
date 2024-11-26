#pragma once
#include <iostream>
#include <vector>
#include "Menu.h"
#include "BlackJack.h"
#include <map>
#include <functional>

Deck pDeck;
Deck hDeck;
bool isGame = false;

void Play() {
    system("cls");
    isGame = true;
    int hiddenscore;


    auto Stand = [&hiddenscore]()
    {
        std::wcout << "You have stood" << std::endl;

        Sleep(5000);

        HousePlay(hiddenscore);

    };

    auto SeeSelfCards = []()
    {
		std::wcout << "These are your cards: " << std::endl;

		std::vector<std::wstring> pCards = pDeck.GetCards();

        for (size_t i = 0; i < pCards.size(); i++) {
            std::wcout << pCards[i] << std::endl;
        };

        Sleep(5000);
    };

    auto SeeOtherCards = []()
        {
            std::wcout << "These are the house's cards: " << std::endl;

            std::vector<std::wstring> hCards = hDeck.GetCards();

            for (size_t i = 0; i < hCards.size(); i++) {
                std::wcout << hCards[i] << std::endl;
            };

            Sleep(5000);
        };

    Menu option1;
    option1.text = L"Hit";
    option1.func = Hit;
    Menu option2;
    option2.text = L"Stand";
    option2.func = Stand;
    Menu option3;
    option3.text = L"See Your Cards";
    option3.func = SeeSelfCards;
    Menu option4;
    option4.text = L"See The House's Cards";
    option4.func = SeeOtherCards;

    std::map<int, Menu> play_list
    {
        {0, option1},
		{1, option2},
		{2, option3},
		{3, option4},

    };

    std::wcout << "These are your starter cards: " << std::endl;

    for (size_t i = 0; i < 2; i++) {
        std::pair<std::wstring, int> Card = CardGenerator();
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
            std::wcout << Card.first << std::endl;
            hDeck.AddCard(Card.first);
            hDeck.UpdateScore(Card.second);
            break;
        }
        case 1:
        {
            std::pair<std::wstring, int> Hidden = GenerateHidden();
            std::wcout << Hidden.first << std::endl;
            hDeck.AddCard(Hidden.first);
            hDeck.UpdateScore(Hidden.second);
			hiddenscore = Hidden.second;
            break;
        }
        }
    };

    Sleep(5000);


    while (isGame) {
        if (pDeck.GetScore() > 21) {
            HousePlay(hiddenscore);
        }
        system("cls");
        RunMenu(play_list, false);
    }
}

void Hit() {
    std::wcout << "You hit" << std::endl;
    std::pair<std::wstring, int> Card = CardGenerator();
    std::wcout << Card.first << std::endl;
    pDeck.AddCard(Card.first);
    pDeck.UpdateScore(Card.second);

    Sleep(5000);


}

void HousePlay(int hiddenscore) {

    std::pair<std::wstring, int> Card = CardGeneratorWithNumber(hiddenscore);
	hDeck.RemoveCard(1);
    hDeck.AddCard(Card.first);
	std::vector<std::wstring> hCards = hDeck.GetCards();

    for (size_t i = 0; i < 2; i++) {
		std::wcout << hCards[i] << std::endl;
	};
    int hScore = hDeck.GetScore();
    int pScore = pDeck.GetScore();
    if (pDeck.GetScore() < 22) {
        while (hScore <= 16) {
            std::pair<std::wstring, int> Card = CardGenerator();
            std::wcout << Card.first << std::endl;
            hDeck.AddCard(Card.first);
            hDeck.UpdateScore(Card.second);
            hScore = hDeck.GetScore();
            Sleep(1000);
        }
        if (hScore > 21) {
            std::wcout << "You win!" << std::endl;
        }
        else if (hScore > pScore) {
            std::wcout << "You lose!" << std::endl;
        }
        else if (hScore <= pScore) {
            std::wcout << "You win!" << std::endl;
        }
	}
	else {
		std::wcout << "You lose!" << std::endl;
	}

    Sleep(5000);
    EndGame();
}

void EndGame() {
	isGame = false;
	hDeck.RemoveCards();
	pDeck.RemoveCards();
	hDeck.ClearScore();
	pDeck.ClearScore();
	CreateMainMenu();
}

void Quit() {
    return;
}

void RunLoadingScreen() {
    for (int i = 1; i < 14; i++) {
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

void CreateMainMenu() {
    system("cls");

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

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    RunLoadingScreen();

	CreateMainMenu();
}