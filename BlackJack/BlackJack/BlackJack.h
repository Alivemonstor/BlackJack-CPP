#pragma once

#include <random>
#include <iostream>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>


std::string CardGenerator();
int random();
std::string random_suit();
void Play();
void Leaderboard();
void Quit();