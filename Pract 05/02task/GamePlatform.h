#pragma once
#include "Games.h"
#include <iostream> 
#include <fstream>

namespace SIZES 
{
	const int GAMES_COUNT = 64;
}

class GamePlatform
{
private:
	Games* gamesList[SIZES::GAMES_COUNT] = { nullptr };
	int gameCount = 0;

	//clean up
	void copyDynamic(const GamePlatform& other);
	void freeDynamic();


public:

	GamePlatform();
	GamePlatform(const GamePlatform& other);
	GamePlatform& operator=(const GamePlatform& other);
	~GamePlatform();

	////move ctor and operator
	//GamePlatform(const GamePlatform&& other);
	//GamePlatform& operator=(const GamePlatform&& other);
	


	//additional
	void addGame(const char* title, const double price, bool isAvailable);
	void printIndexGame(const char* title) const;
	void printAllGames() const;
	double printCheapest() const;
	double printMostExpensive() const;
	void printAllFree() const;
	void removeGame(const char* title);
	Games* getGame(int index) const;
	int getGameCount() const;
	


};
