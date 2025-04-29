#include <iostream>

enum class DayOfWeek
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

DayOfWeek getNextDay(DayOfWeek &day)
{
	switch (day)
	{
	case DayOfWeek::MONDAY:
		return DayOfWeek::TUESDAY;

	case DayOfWeek::TUESDAY:
		return DayOfWeek::WEDNESDAY;

	case DayOfWeek::WEDNESDAY:
		return DayOfWeek::THURSDAY;

	case DayOfWeek::THURSDAY:
		return DayOfWeek::FRIDAY;

	case DayOfWeek::FRIDAY:
		return DayOfWeek::SATURDAY;

	case DayOfWeek::SATURDAY:
		return DayOfWeek::SUNDAY;

	case DayOfWeek::SUNDAY:
		return DayOfWeek::MONDAY;
	}
}


int main()
{

	DayOfWeek result = getNextDay(DayOfWeek::FRIDAY);

	switch (result)
	{
	case DayOfWeek::MONDAY:
		std::cout << "Monday";
		break;
	case DayOfWeek::TUESDAY:
		std::cout << "Tuesday";
		break;
	case DayOfWeek::WEDNESDAY:
		std::cout << "Wednesday";
		break;
	case DayOfWeek::THURSDAY:
		std::cout << "Thursday";
		break;
	case DayOfWeek::FRIDAY:
		std::cout << "Friday";
		break;
	case DayOfWeek::SATURDAY:
		std::cout << "Saturday";
		break;
	case DayOfWeek::SUNDAY:
		std::cout << "Sunday";
		break;
	default:
		std::cout << "Incorrect day";
	}
}