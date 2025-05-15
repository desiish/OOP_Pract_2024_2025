#include "Team.h"

size_t Team::_idCounter = 0;

Team::Team() : _eliminated(false), _id(_idCounter++) {}

Team::Team(Person* team, bool eliminated) : _eliminated(eliminated), _id(_idCounter++) {
    for (int i = 0; i < Constants::MIN_TEAM_SIZE; ++i) {
        _team[i] = team[i]; 
    }
}

Team::Team(const Team& other) : _id(other._id), _eliminated(other._eliminated) {
    for (int i = 0; i < Constants::MIN_TEAM_SIZE; ++i) {
        _team[i] = other._team[i];
    }
}

Team& Team::operator=(const Team& other) {
    if (this != &other) {
        _id = other._id;
        _eliminated = other._eliminated;
        for (int i = 0; i < Constants::MIN_TEAM_SIZE; ++i) {
            _team[i] = other._team[i];
        }
    }
    return *this;
}

Team::~Team() {
}

//getters
unsigned Team::getId() const {
    return _id;
}

Person* Team::getTeam() const {
    return const_cast<Person*>(_team); 
}

bool Team::getIsEliminated() const {
    return _eliminated;
}

//setters
void Team::setTeam(Person* team) {
    for (int i = 0; i < Constants::MIN_TEAM_SIZE; ++i) {
        _team[i] = team[i];
    }
}

void Team::setIsEliminated(bool eliminated) {
    _eliminated = eliminated;
}
