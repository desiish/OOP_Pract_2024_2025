#pragma once
#include "Question.h"

constexpr unsigned short COUNT_OF_QUESTIONS = 20;

struct Test {
	Question questions[COUNT_OF_QUESTIONS];
};

void initTest(Test& test);
int solveTest(const Test& test);
