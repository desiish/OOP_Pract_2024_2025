#include <iostream>
#include "NumberSeries.h"

int plusTwo(int x) 
{
    return x + 2;
}
int timesThree(int x)
{
    return x * 3;
}

int main()
{
    NumberSeries serie{2, plusTwo};
    //generating only when you want to see if a number is in the series 
    serie.getAtIndex(10);
    std::cout << std::boolalpha << serie.isInSeries(8) << std::endl;

    serie.changeStarterValue(1);
    //serie.changeFunction(timesThree);
    serie.getAtIndex(10);

    serie.printSeries();
}
