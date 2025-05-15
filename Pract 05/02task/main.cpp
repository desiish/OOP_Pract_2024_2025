#include "Games.h"
#include "GamePlatform.h"
#include <iostream>
int main()
{
	try
	{
		GamePlatform platform1;
		platform1.addGame("Animal Jam", 0, true);
		platform1.addGame("Tanki online", 0, true);
		platform1.addGame("Minecraft", 26.95, true);

		//works
		std::cout << "PRINT ALL GAMES: \n";
		platform1.printAllGames();

		//works
		std::cout << "\n\nPRINT A GAME: \n";
		platform1.printIndexGame("Animal Jam");

		//works
		std::cout << "\n\nCHEAPEST: $" << platform1.printCheapest() << std::endl;
		std::cout << "MOST EXPENSIVE: $" << platform1.printMostExpensive() << std::endl;

		//works
		std::cout << "\n\nPRINT ALL FREE GAMES: \n";
		platform1.printAllFree();

		//works
		std::cout << "\n\nREMOVE A GAME: \n";
		platform1.removeGame("Tanki online");
		std::cout << "done";
		//platform1.printAllGames();

		//WRITE - works
		std::ofstream writeFile("C:\\Users\\vikik\\Desktop\\example.txt");
		if (!writeFile)
		{
			std::cerr << "Error opening file to write!\n";
		}
		for (int i = 0; i < platform1.getGameCount(); ++i) {
			if (platform1.getGame(i)) {
				platform1.getGame(i)->writeToStream(writeFile);
			}
		}
		writeFile.close();
		std::cout << "\nGames written to file.\n";


		//READ
		GamePlatform templPlatform;
		std::ifstream readFile("C:\\Users\\vikik\\Desktop\\example.txt");
		if (!readFile)
		{
			std::cerr << "Error opening file to read!\n";
		}
		while (!readFile.eof())
		{
			Games* templ = new Games("template", 0, true);
			try
			{
				templ->readFromStream(readFile);
				templPlatform.addGame(templ->getTitle(), templ->getPrice(), templ->getIsAvailable());

			}
			catch (...)
			{
				delete templ;
				break;
			}
			delete templ;
		}
		readFile.close();
		std::cout << "Loaded info successfully. Printing all info from file now: \n";
		templPlatform.printAllGames();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (const std::runtime_error& e) 
	{
		std::cout << e.what();
	}
}
