#pragma once
namespace Constants
{
    const int STARTER_SIZE = 2;
	const int GENERATION_LIMIT = 100;
}

class NumberSeries
{
private:
	int a0;
	int (*transitionFunction)(int);
	int* series;
	int capacity;
	int currIndex;


private:
	void freeDynamic();
	void copyDynamic(const NumberSeries& other);
public:
	NumberSeries() = delete;
	NumberSeries(int a0, int (*transitionFunction)(int));
	NumberSeries(const NumberSeries& other);
	NumberSeries& operator=(const NumberSeries& other);
	~NumberSeries();

	void setStarterValue(int a0);
	void setFunction(int (*transitionFunction)(int));
	//void setSeries(int* series);
	//void setCapacity(int capacity);
	//void setCurrentIndex(int currIndex);

	int getStarterValue() const;
	int (*getFunction() const)(int);
	int* getSeries() const;
	int getCapacity() const;
	int getCurrentIndex() const;
	
	//print series
	void printSeries() const;
	//find if number is in the series
	bool isInSeries(int number);
	//return existing number from the series
	int getAtIndex(int number);
	//if number is not in array, it's said to add all the missing int including the given number;
	//the call returnNumberFromSeries(); again

	//resize series
	void resizeSeries();
	//set new starterValue
	void changeStarterValue(int newA0);
	//set new function
	void changeFunction(int (*newFunction)(int));
};
