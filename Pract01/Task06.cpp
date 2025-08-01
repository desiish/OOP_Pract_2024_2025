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

struct Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
	DayOfWeek dayOfWeek;
};

void setDate(Date& date)
{

	int dayOfTheWeek = date.day + (13 * (date.month + 1) / 5) + (date.year % 100) + ((date.year % 100) / 4)
		+ ((date.year / 100) / 4) - (2 * (date.year / 100)) % 7;

	int dayToPrint = ((dayOfTheWeek + 5) % 7) + 1;

	switch (dayToPrint) {
	case 1:
		date.dayOfWeek = DayOfWeek::MONDAY;
		break;
	case 2:
		date.dayOfWeek = DayOfWeek::TUESDAY;
		break;
	case 3:
		date.dayOfWeek = DayOfWeek::WEDNESDAY;
		break;
	case 4:
		date.dayOfWeek = DayOfWeek::THURSDAY;
		break;
	case 5:
		date.dayOfWeek = DayOfWeek::FRIDAY;
		break;
	case 6:
		date.dayOfWeek = DayOfWeek::SATURDAY;
		break;
	case 7:
		date.dayOfWeek = DayOfWeek::SUNDAY;
		break;
	}

}

int main()
{
	Date date = { 1,3,2025 };
	setDate(date);

	std::cout << "Day: " << date.day << std::endl;
	std::cout << "Month: " << date.month << std::endl;
	std::cout << "Year: " << date.year << std::endl;

	std::cout << "Day Of Week: ";
	switch (date.dayOfWeek)
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