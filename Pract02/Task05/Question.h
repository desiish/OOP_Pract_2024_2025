#pragma once
#include <iostream>
#include "Answer.h"

constexpr unsigned short COUNT_OF_ANSWERS = 4;

struct Question
{
	char correctAnswer;
	unsigned short pointPerCorrectAnswer;
	char title[50 + 1];
	Answer answers[COUNT_OF_ANSWERS];

};

void initQuestion(Question& question);
void printQuestion(const Question question);
int answerQuestion(const Question& question);