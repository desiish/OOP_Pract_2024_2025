#include <iostream>

struct Date {
    enum class dayOfWeek : short {
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY
    };
    int year;
    short day;
    short month;
    dayOfWeek today;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

short calculateWeekDay(short day, short month, int year) {
    int monthCodes[] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if (isLeapYear(year) && month > 2) {
        monthCodes[1] = 3; 
    }

    if (month < 3) {
        year -= 1;
    }

    int yearCode = (year % 100) + (year % 100) / 4;
    yearCode = (yearCode + (year / 100) / 4 + 5 * (year / 100)) % 7;

    return (day + monthCodes[month - 1] + yearCode) % 7;
}

void setWeekDay(Date& date, short weekDay) {
    switch (weekDay) {
    case 0: date.today = Date::dayOfWeek::SUNDAY; break;
    case 1: date.today = Date::dayOfWeek::MONDAY; break;
    case 2: date.today = Date::dayOfWeek::TUESDAY; break;
    case 3: date.today = Date::dayOfWeek::WEDNESDAY; break;
    case 4: date.today = Date::dayOfWeek::THURSDAY; break;
    case 5: date.today = Date::dayOfWeek::FRIDAY; break;
    case 6: date.today = Date::dayOfWeek::SATURDAY; break;
    default: break;
    }
}

const char* dayToString(Date& date) {
    switch (date.today) {
    case Date::dayOfWeek::MONDAY: return "Monday";
    case Date::dayOfWeek::TUESDAY: return "Tuesday";
    case Date::dayOfWeek::WEDNESDAY: return "Wednesday";
    case Date::dayOfWeek::THURSDAY: return "Thursday";
    case Date::dayOfWeek::FRIDAY: return "Friday";
    case Date::dayOfWeek::SATURDAY: return "Saturday";
    case Date::dayOfWeek::SUNDAY: return "Sunday";
    default: return "Invalid day! Returning Sunday.";
    }
}

int main() {
    std::cout << "Enter day, month, and year: \n";
    short day, month;
    int year;
    std::cin >> day >> month >> year;

    Date date1 = { year, day, month };
    short weekDay = calculateWeekDay(day, month, year);
    setWeekDay(date1, weekDay);

    std::cout << "This day is on a " << dayToString(date1) << std::endl;
}
