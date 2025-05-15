#include "NumberSeries.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

void NumberSeries::freeDynamic()
{
	currIndex = 0;
	capacity = 0;
	series = nullptr;
	delete[] series;

}
void NumberSeries::copyDynamic(const NumberSeries& other)
{
	/*handle them inside copyDynamic() when used in other places like operator=, 
	where they may not yet be updated*/
	capacity = other.capacity;
	currIndex = other.currIndex;
	series = new int[other.capacity];
	for (int i = 0; i < other.currIndex; i++)
	{
		series[i] = other.series[i];
	}
}
NumberSeries::NumberSeries(int a0, int (*transitionFunction)(int))
	:a0(a0), transitionFunction(transitionFunction), capacity(Constants::STARTER_SIZE), currIndex(0)
{
	series = new int[capacity];
	series[0] = a0;
	currIndex = 1;
}
NumberSeries::NumberSeries(const NumberSeries& other)
	:a0(other.a0), transitionFunction(other.transitionFunction), capacity(other.capacity), currIndex(other.currIndex)
{
	copyDynamic(other);
}
NumberSeries& NumberSeries::operator=(const NumberSeries& other)
{
	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);
	}
	return *this;
}
NumberSeries::~NumberSeries()
{
	freeDynamic();
}

//SETTERS
void NumberSeries::setStarterValue(int a0)
{
	this->a0 = a0;
}
void NumberSeries::setFunction(int (*transitionFunction)(int))
{
	if (this->transitionFunction == transitionFunction)
	{	
		return;
	}
	this->transitionFunction = transitionFunction;
	freeDynamic();
	capacity = Constants::STARTER_SIZE;
	series = new int[capacity];
	series[0] = a0;
	currIndex = 1;
}

//GETTERS
int NumberSeries::getCapacity() const
{
	return this->capacity;
}

int NumberSeries::getCurrentIndex() const
{
	return this->currIndex;
}

int NumberSeries::getStarterValue() const
{
	return this->a0;
}

int (*NumberSeries::getFunction() const)(int)
{
	return this->transitionFunction;
}

int* NumberSeries::getSeries() const
{
	int* copy = new int[currIndex];
	for (int i = 0; i < currIndex; ++i)
		copy[i] = series[i];
	return copy;
}

//ADDITIONAL
void NumberSeries::resizeSeries()
{
	int newCapacity = capacity * 2;
	int* newSeries = new int[newCapacity];
	for (int i = 0; i < currIndex; ++i)
	{
		newSeries[i] = series[i];
	}
	delete[] series;
	series = newSeries;
	capacity = newCapacity;
}


int NumberSeries::getAtIndex(int index)
{
	if (index < 0)
	{
		throw std::out_of_range("Index must be valid.\n");
	}
	//if generated
	if (index < currIndex)
	{
		return series[index];
	}

	while (currIndex <= index)
	{
		if (currIndex >= capacity)
		{
			resizeSeries();
		}
		series[currIndex] = transitionFunction(series[currIndex - 1]);
		++currIndex;
	}
	return series[index];
}

bool NumberSeries::isInSeries(int number)
{
	for (int i = 0; i < currIndex; ++i)
	{
		if(number == series[i])
		{
			return true;
		}
	}

	//here: if number is not in the serie yet
	while (true)
	{
		if (currIndex >= capacity)
		{
			resizeSeries();
		}

		//"generating"
		int next;
		if (currIndex == 0)
		{
			next = a0;
		}
		else
		{
			next = transitionFunction(series[currIndex - 1]);
		}
		//adding new element
		series[currIndex++] = next;
		
		if (next == number)
		{
			return true;
		}

		if (currIndex > Constants::GENERATION_LIMIT)
		{
			return false;
		}
	}
}


void NumberSeries::changeStarterValue(int number)
{
	a0 = number;
	freeDynamic();

	capacity = Constants::STARTER_SIZE;
	currIndex = 0;
	series = new int[capacity];
	series[currIndex++] = a0;
}

void NumberSeries::changeFunction(int (*newFunction)(int))
{
	transitionFunction = newFunction;
	freeDynamic();

	capacity = Constants::STARTER_SIZE;
	currIndex = 0;
	series = new int[capacity];
	series[currIndex++] = a0;
}

void NumberSeries::printSeries() const
{
	std::cout << "Serie:\n";
	for (int i = 0; i < currIndex; ++i)
	{
		std::cout << series[i] << std::endl;
	}
}
