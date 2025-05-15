#include "GamePlatform.h"
#include <iostream> 

//copy and free dynamixc
void GamePlatform::copyDynamic(const GamePlatform& other)
{
	for (int i = 0; i < SIZES::GAMES_COUNT; ++i)
	{
		if (other.gamesList[i])
		{
			gamesList[i] = new Games(*other.gamesList[i]);
		}
		else
		{
			gamesList[i] = nullptr;
		}
	}

}

void GamePlatform::freeDynamic()
{
	for (int i = 0; i < SIZES::GAMES_COUNT; ++i)
	{
		delete gamesList[i];
		gamesList[i] = nullptr;
	}
	gameCount = 0;
}

//copy ctor
GamePlatform::GamePlatform(const GamePlatform& other)
	:gameCount(other.gameCount)
{
	copyDynamic(other);
}

//operator=
GamePlatform& GamePlatform::operator=(const GamePlatform& other)
{
	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);
	}
	return *this;	
}

//ctor
GamePlatform::GamePlatform()
{
	for (int i = 0; i < SIZES::GAMES_COUNT; ++i)
	{
		gamesList[i] = nullptr;
	}
}
////move ctor
//GamePlatform::GamePlatform(const GamePlatform&& other) noexcept
//	:gameCount(other.gameCount)
//{
//	for (int i = 0; i < SIZES::GAMES_COUNT; ++i) 
//	{
//		gamesList[i] = other.gamesList[i];
//		other.gamesList[i] = nullptr;
//	}
//	other.gameCount = 0;
//}
//move operator=
//GamePlatform& GamePlatform::operator=(const GamePlatform&& other) noexcept
//{
//	if (this != &other)
//	{
//		freeDynamic();
//		gameCount = other.gameCount;
//		for (int i = 0; i < SIZES::GAMES_COUNT; ++i)
//		{
//			gamesList[i] = other.gamesList[i];
//			other.gamesList[i] = nullptr;
//		}
//		other.gameCount = 0
//	}
//	return *this;
//}


//dtor
GamePlatform::~GamePlatform()
{
	freeDynamic();
}

//ADD GAME
void GamePlatform::addGame(const char* title, const double price, bool isAvailable)
{
	if (gameCount >= SIZES::GAMES_COUNT || !isAvailable)
	{
		throw std::invalid_argument("Too many games, or game not available to add!\n");
		return;
	}
	gamesList[gameCount++] = new Games(title, price, isAvailable);
}

//PRINT ALL GAMES
void GamePlatform::printAllGames() const
{
	for (int i = 0; i < gameCount; ++i)
	{
		if (gamesList[i])
		{
			gamesList[i]->print();
		}
	}
}

//PRINT A CERTAIN GAME
void GamePlatform::printIndexGame(const char* title) const
{
	for (int i = 0; i < gameCount; ++i)
	{
		if (gamesList[i] && std::strcmp(gamesList[i]->getTitle(), title) == 0)
		{
			gamesList[i]-> print();
		}
	}
	return;
}

//PRINT CHEAPEST GAME
double GamePlatform::printCheapest() const
{
	double lowestPrice = gamesList[0]->getPrice();
	for (int i = 0; i < gameCount; ++i)
	{
		if (gamesList[i]->getPrice() < lowestPrice)
		{
			lowestPrice = gamesList[i]->getPrice();
		}
	}
	return lowestPrice;
}

//PRINT MOST EXPENSIVE GAME
double GamePlatform::printMostExpensive() const
{
	double highestPrice = gamesList[0]->getPrice();
	for (int i = 0; i < gameCount; ++i)
	{
		if (gamesList[i]->getPrice() > highestPrice)
		{
			highestPrice = gamesList[i]->getPrice();
		}
	}
	return highestPrice;
}

//PRINT ALL FREE GAMES
void GamePlatform::printAllFree() const
{
	for (int i = 0; i < gameCount; ++i)
	{
		if (gamesList[i]->getPrice() == 0)
		{
			gamesList[i]->print();
		}
	}
}

//REMOVE GAME
void GamePlatform::removeGame(const char* title)
{
	for (int i = 0; i < gameCount; ++i) 
	{
		if (gamesList[i] && std::strcmp(gamesList[i]->getTitle(), title) == 0) 
		{
			delete gamesList[i];
			for (int j = i; j < gameCount - 1; ++j) 
			{
				gamesList[j] = gamesList[j + 1];
			}
			gamesList[gameCount - 1] = nullptr;
			--gameCount;
			return;
		}
	}
}

//get game and count
Games* GamePlatform::getGame(int index) const
{
	if (index >= 0 && index < gameCount)
	{
		return gamesList[index];
	}
	return nullptr;
}

int GamePlatform::getGameCount() const
{
	return gameCount;
}

