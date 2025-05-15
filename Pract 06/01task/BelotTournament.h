#include "Team.h"

namespace Constants
{
	const int MIN_TEAMS_COUNT = 3;
	const int POINTS_TO_WIN = 151;
	const int MAX_ROUND_COUNT = 3;
}

class BelotTournament
{
private:
	Team* _tournament;
	int _teamCount;
	double _charityMoney;

private:
	void freeDynamic();
	void copyDynamic(const BelotTournament& other);

	void randomizeTeams();
	void startDuel(Team& t1, Team& t2);
	void removeLosingTeams();


public:
	BelotTournament();
	BelotTournament(Team* tournament, int teamCount, double charityMoney);
	BelotTournament(const BelotTournament& other);
	BelotTournament& operator=(const BelotTournament& other);
	~BelotTournament();
	BelotTournament(BelotTournament&& other) noexcept;
	BelotTournament& operator=(BelotTournament&& other) noexcept;


	//getters and setters
	const Team* getTournament() const;
	int getTeamCount() const;
	double getCharityMoney() const;


	void setTournament(Team* teams, int teamCount, double charityMoney);

	////additional
	////void deleteTeam(Team* tournament);
	//void randomizeTeams();
	void startTournament();
	////void fight(int teamCount, Team* tournament);
	////void round(int teamCount, Team* tournament);
};
