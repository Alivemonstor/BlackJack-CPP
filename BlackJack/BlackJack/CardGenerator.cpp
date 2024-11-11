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

    const char8_t* a = u8"\u2660";
    const char8_t* b = u8"\u2665";
    const char8_t* c = u8"\u2666";
    const char8_t* d = u8"\u2663";


    std::u8string CHARACTERS; 
    
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

    std::uniform_int_distribution<int> udist(1, 14);

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
    int genRandom = random();
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




