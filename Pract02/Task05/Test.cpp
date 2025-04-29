#include "Test.h"
#include <iostream>

void initTest(Test& test)
{
	for (int i = 0; i < COUNT_OF_QUESTIONS; i++)
	{
		initQuestion(test.questions[i]);
	}
}

int solveTest(const Test& test)
{
	unsigned int points = 0;
	for (int i = 0; i < COUNT_OF_QUESTIONS; i++)
	{
		points += answerQuestion(test.questions[i]);
	}

	return points;
}
