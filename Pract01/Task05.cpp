#include <iostream>

enum class Season
{
	WINTER,
	SPRING,
	SUMMER,
	AUTUMN
};

Season getNextSeason(Season& season)
{
	switch (season)
	{
	case Season::WINTER:
		return Season::SPRING;

	case Season::SPRING:
		return Season::SUMMER;

	case Season::SUMMER:
		return Season::AUTUMN;

	case Season::AUTUMN:
		return Season::WINTER;
	}

}

const char* getSeasonName(Season& season)
{
	switch (season)
	{
	case Season::SPRING:
		return "Spring";

	case Season::SUMMER:
		return "Summer";

	case Season::AUTUMN:
		return "Autumn";

	case Season::WINTER:
		return "Winter";
	}
}

int main()
{
	Season season = Season::SUMMER;
	Season nextSeason = getNextSeason(season);

	std::cout << getSeasonName(nextSeason);
}