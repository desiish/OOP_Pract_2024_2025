#include "Answer.h"

static void setSymbol(Answer& answer, unsigned short symbol)
{
	switch (symbol)
	{
	case 1:
		answer.symbol = 'A';
		break;
	case 2:
		answer.symbol = 'B';
		break;
	case 3:
		answer.symbol = 'C';
		break;
	case 4:
		answer.symbol = 'D';
		break;
	}

}

void initAnswer(Answer& answer, unsigned short symbol)
{
	setSymbol(answer, symbol);

	do {
		std::cout << "Enter answer (max 50 characters): ";

		std::cin >> std::ws;
		std::cin.getline(answer.text, 51);

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}

	} while (strlen(answer.text) == 0 || strlen(answer.text) > 50);
}

void printAnswer(const Answer& answer)
{
	std::cout << answer.symbol << ") " << answer.text << "\n";
}