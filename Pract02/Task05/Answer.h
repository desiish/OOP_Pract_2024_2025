#pragma once
#include <iostream>

struct Answer {
	char text[50 + 1];
	char symbol;
};

void initAnswer(Answer& answer, unsigned short symbol);
void printAnswer(const Answer& answer);