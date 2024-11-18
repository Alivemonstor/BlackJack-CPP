#pragma once

#include <random>
#include <iostream>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <windows.h>



class Deck {
private:
	std::vector<std::wstring> Cards;
	int TotalScore;

public:
	void AddCard(std::wstring Card) {
		Cards.push_back(Card);
	};
	void RemoveCards() {
		Cards.clear();
	};
	std::wstring GetCard(int index) {
		return Cards[index];
	};
	void UpdateScore(int score) {
		TotalScore += score;
	}
	int GetScore() {
		return TotalScore;
	}
};


std::pair<std::wstring, int> GenerateHidden();
std::pair<std::wstring, int> CardGenerator();
int random();
std::wstring random_suit();
void Play();
void Leaderboard();
void Quit();
void Ask();