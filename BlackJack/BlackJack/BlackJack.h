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
	void RemoveCard(int index) {
		Cards.erase(Cards.begin() + index);
	};
	void RemoveCards() {
		Cards.clear();
	};
	std::vector<std::wstring> GetCards() {
		return Cards;
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
	void ClearScore() {
		TotalScore = 0;
	}
};


std::pair<std::wstring, int> GenerateHidden();
std::pair<std::wstring, int> CardGenerator();
std::pair<std::wstring, int> CardGeneratorWithNumber(int number);
void RunLoadingScreen();
int random();
std::wstring random_suit();
void Play();
void HousePlay(int hiddenscore);
void Quit();
void Hit();
void EndGame();
void CreateMainMenu();