#pragma once
#include "Person.h"

class Team 
{
private:
	static size_t _idCounter;
	unsigned _id;
	Person _team[Constants::MIN_TEAM_SIZE];
	bool _eliminated;

	//no free and copy dynamic

public:
	Team();
	Team(Person* team, bool eliminated);
	Team(const Team& other);
	Team& operator=(const Team& other);
	~Team();
	
	//getters
	unsigned getId() const;
	Person* getTeam() const;
	bool getIsEliminated() const;

	//setters
	void setTeam(Person* team);
	void setIsEliminated(bool eliminated);
	//void setId(size_t idCounter);

};
