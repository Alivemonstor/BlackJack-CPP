#pragma once

#include <random>
#include <iostream>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream>


std::wstringstream CardGenerator();
int random();
std::wstring random_suit();
void Play();
void Leaderboard();
void Quit();