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

std::wstringstream CardGenerator() {
    std::wstring output;
    std::map<int, std::wstring> convert {
        {11, L"A"},
        {12, L"K"},
        {13, L"J"},
        {14, L"Q"}
    };

    //1 2 3 4 5 6 7 8 9 10 11 k j q

    int genRandom = random();
    std::wstring suit = random_suit();

    if (convert.contains(genRandom)) {
        output = convert[genRandom];
    }
    else {
		output = std::to_wstring(genRandom);
    }

    std::wstringstream top;
    std::wstringstream bottom;
    std::wstringstream toOut;


    toOut << L"┌───────────┐\n";
    for (size_t i = 0; i < 8; i++) {
        if (genRandom != 10) {
            if (i == 0) {
                toOut << L"│" << output << suit << L"         │" << L"\n";
            }
            else if (i == 3) {
                toOut << L"│     " << suit << L"     │" << L"\n";
            }
            else if (i == 7) {
                toOut << L"│         " << output << suit << L"│" << L"\n";
            }
            else {
                toOut << L"│           │" << L"\n";
            }
        }
        else {
            if (i == 0) {
                toOut << L"│" << output << suit << L"        │" << L"\n";
            }
            else if (i == 3) {
                toOut << L"│     " << suit << L"     │" << L"\n";
            }
            else if (i == 7) {
                toOut << L"│        " << output << suit << L"│" << L"\n";
            }
            else {
                toOut << L"│           │" << L"\n";
            }
        }


    }
    
    toOut << L"└───────────┘";

    return toOut;
};




