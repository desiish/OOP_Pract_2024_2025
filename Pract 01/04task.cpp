#include <iostream>
enum class dayOfWeek {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY

};
dayOfWeek nextDay(dayOfWeek day) {
	switch (day)
	{
	case dayOfWeek::MONDAY:
		return dayOfWeek::TUESDAY;
	case dayOfWeek::TUESDAY:
		return dayOfWeek::WEDNESDAY;
	case dayOfWeek::WEDNESDAY:
		return dayOfWeek::THURSDAY;
	case dayOfWeek::THURSDAY:
		return dayOfWeek::FRIDAY;
	case dayOfWeek::FRIDAY:
		return dayOfWeek::SATURDAY;
	case dayOfWeek::SATURDAY:
		return dayOfWeek::SUNDAY;
	case dayOfWeek::SUNDAY:
		return dayOfWeek::MONDAY;
	default:
		std::cerr << "\nInvalid day! Returning Sunday.\n";
		return dayOfWeek::SUNDAY;
		break;
	}

}
const char* dayToString(dayOfWeek day) {
	switch (day) {
	case dayOfWeek::SUNDAY: return "Sunday";
	case dayOfWeek::MONDAY: return "Monday";
	case dayOfWeek::TUESDAY: return "Tuesday";
	case dayOfWeek::WEDNESDAY: return "Wednesday";
	case dayOfWeek::THURSDAY: return "Thursday";
	case dayOfWeek::FRIDAY: return "Friday";
	case dayOfWeek::SATURDAY: return "Saturday";
	default: return "Invalid day! Returning Sunday.";
	}
}

int main() {
	dayOfWeek tomorrow = nextDay(dayOfWeek::SUNDAY);

	std::cout << "Tomorrow is " << dayToString(tomorrow) << " !";
}
