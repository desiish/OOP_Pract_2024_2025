#include <iostream>
enum class Season {
	SPRING,
	SUMMER,
	AUTUMN,
	WINTER
};
Season nextSeason(Season day) {
	switch (day)
	{
	case Season::SPRING:
		return Season::SUMMER;
	case Season::SUMMER:
		return Season::AUTUMN;
	case Season::AUTUMN:
		return Season::WINTER;
	case Season::WINTER:
		return Season::SPRING;
	default:
		std::cerr << "\nInvalid season! Returning spring.\n";
		return Season::SPRING;
		break;
	}
}
const char* getSeasonName(Season day) {
	switch (day) {
	case Season::SPRING: return "Spring";
	case Season::SUMMER: return "Summer";
	case Season::AUTUMN: return "Autumn";
	case Season::WINTER: return "Winter";
	default: return "Invalid season!";
	}
}

int main() {
	Season season = nextSeason(Season::WINTER);

	std::cout << "It is " << getSeasonName(season) << " !";
}
