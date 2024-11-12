#pragma once
#include <iostream>
#include <vector>
#include "BlackJack.h"
#include <map>
#include <string>
#include <sstream>


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
    int min = std::min(1, 14);
    int max = std::max(14, 1);

    std::uniform_int_distribution<int> udist(min, max);

    return udist(randomGenerator);
}

std::wstring CardGenerator() {
    std::wstring output;
    std::map<int, std::wstring> convert {
        {12, L"K"},
        {13, L"K"},
        {14, L"K"}
    };

    //1 2 3 4 5 6 7 8 9 10 11 k j q
    int genRandom = random();
    std::wstring suit = random_suit();
    std::wcout << suit << std::endl;

    if (convert.contains(genRandom)) {
        std::wstring output = convert[genRandom];
    }
    else {
        //std::wstring output = std::to_string(genRandom);
    }

    std::wstringstream top;
    std::wstringstream bottom;
    std::wstringstream side;

    top << R"(┌─────────┐)";
    bottom << L'└─────────┘';
    side << L'│         │';

    std::wcout << top.str() << std::endl;
    std::wcout << side.str() << std::endl;
    std::wcout << bottom.str() << std::endl;



    return output;
};




