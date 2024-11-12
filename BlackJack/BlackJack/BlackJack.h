#pragma once

#include <random>
#include <iostream>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>


std::wstring CardGenerator();
int random();
std::wstring random_suit();
void Play();
void Leaderboard();
void Quit();