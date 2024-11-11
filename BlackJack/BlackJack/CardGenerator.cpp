#pragma once
#include <iostream>
#include <vector>
#include "BlackJack.h"
#include <map>
#include <string>
#include <sstream>


std::string random_suit()
{

    std::random_device device;
    std::mt19937 randomGenerator(device());


    wchar_t a = L'\u2660';
    wchar_t b = L'\u2665';
    wchar_t c = L'\u2666';
    wchar_t d = L'\u2663';


    std::string CHARACTERS; 

    CHARACTERS += a;
    CHARACTERS += b;
    CHARACTERS += c;
    CHARACTERS += d;


    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

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

std::string CardGenerator() {
    std::string output;
    std::map<int, std::string> convert {
        {12, "k"},
        {13, "j"},
        {14, "q"}
    };

    //1 2 3 4 5 6 7 8 9 10 11 k j q
    int genRandom = 0;
    std::string suit = random_suit();
    std::cout << suit << std::endl;

    if (convert.contains(genRandom)) {
        std::string output = convert[genRandom];
    }
    else {
        std::string output = std::to_string(genRandom);
    }

    std::stringstream top;
    std::stringstream bottom;
    std::stringstream side;

    top << "┌─────────┐";
    bottom << "└─────────┘";
    side << "│         │";

    std::cout << top.str() << std::endl;
    std::cout << side.str() << std::endl;
    std::cout << bottom.str() << std::endl;







    return output;
};




