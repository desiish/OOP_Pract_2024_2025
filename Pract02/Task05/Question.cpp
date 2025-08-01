#include "Question.h"

static void setCorrectAnswerSymbol(Question& question)
{
	do {
		std::cout << "Enter the correct answer:(A, B, C, D) ";
		std::cin >> question.correctAnswer;
	} while (question.correctAnswer != 'A' && question.correctAnswer != 'B'
		&& question.correctAnswer != 'C' && question.correctAnswer != 'D');
}

static void setPointsPerCorrectAnswer(Question& question)
{
	do {
		std::cout << "Enter points per correct answer: ";
		std::cin >> question.pointPerCorrectAnswer;
	} while (question.pointPerCorrectAnswer < 1);
}

static void setTitle(Question& question)
{

	do {
		std::cout << "Enter question title: ";

		std::cin >> std::ws;
		std::cin.getline(question.title, 51);

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}

	} while (strlen(question.title) == 0 || strlen(question.title) > 50);

}

void initQuestion(Question& question)
{
	setTitle(question);

	for (int i = 0; i < COUNT_OF_ANSWERS; i++)
	{
		initAnswer(question.answers[i], i + 1);
	}

	setCorrectAnswerSymbol(question);
	setPointsPerCorrectAnswer(question);
}

void printQuestion(const Question question)
{
	std::cout << question.title;

	for (int i = 0; i < COUNT_OF_ANSWERS; i++)
	{
		printAnswer(question.answers[i]);
	}

}

int answerQuestion(const Question& question)
{
	printQuestion(question);

	char answer;

	do {
		std::cout << "Enter your answer:(A, B, C, D) ";
		std::cin >> answer;
	} while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D');

	if (answer == question.correctAnswer)
		return question.pointPerCorrectAnswer;

	return 0;
}
