#pragma once
#include <iostream>
#include <vector>
#include "BlackJack.h"
#include <map>
#include <string>


std::wstring random_suit()
{
    std::random_device device;
    std::mt19937 randomGenerator(device());

    wchar_t a = L'\u2660';
    wchar_t b = L'\u2665';
    wchar_t c = L'\u2666';
    wchar_t d = L'\u2663';


    std::wstring CHARACTERS; 

    CHARACTERS += a;
    CHARACTERS += b;
    CHARACTERS += c;
    CHARACTERS += d;
    

    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::wstring random_string;

    random_string += CHARACTERS[distribution(randomGenerator)];

    return random_string;
}

int random()
{
    std::random_device device;
    std::mt19937 randomGenerator(device());

    std::uniform_int_distribution<int> udist(1, 14);

    return udist(randomGenerator);
}

std::pair<std::wstring, int> CardGenerator() {
    std::wstring output;
    std::map<int, std::wstring> convert {
        {11, L"A"},
        {12, L"K"},
        {13, L"J"},
        {14, L"Q"}
    };

    //1 2 3 4 5 6 7 8 9 10 a k j q

    int genRandom = random();
    std::wstring suit = random_suit();

    if (convert.contains(genRandom)) {
        output = convert[genRandom];
    }
    else {
		output = std::to_wstring(genRandom);
    }

    std::wstringstream toOut;


    toOut << L"┌───────────┐\n";
    for (size_t i = 0; i < 8; i++)
    {
        std::wstring padding = genRandom == 10 ? L"" : L" ";

        switch (i)
        {
        case 0:
        {
            toOut << L"│" << output << suit << L"        " << padding << L"│" << L"\n";
            break;
        }
        case 3:
        {
            toOut << L"│     " << suit << L"     │" << L"\n";
            break;
        }
        case 7:
        {
            toOut << L"│        " << padding << output << suit << L"│" << L"\n";
            break;
        }
        default:
        {
            toOut << L"│           │" << L"\n";
            break;
        }
        }
    }

    toOut << L"└───────────┘\n";

    if (genRandom > 11) {
        genRandom = 10;
    }

    std::pair<std::wstring, int> returnValues = std::make_pair(toOut.str(), genRandom);

    return returnValues;
};

std::pair<std::wstring, int> GenerateHidden() {
    std::wstringstream toOut;

    toOut << L"┌───────────┐\n";
    for (size_t i = 0; i < 8; i++)
    {
        toOut << L"│***********│" << L"\n";
    }

    toOut << L"└───────────┘\n";

    int genRandom = random();

    if (genRandom > 10) {
        genRandom = 10;
    }


    std::pair<std::wstring, int> returnValues = std::make_pair(toOut.str(), genRandom);

    return returnValues;
};

