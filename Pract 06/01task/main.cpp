#pragma warning (disable : 4996) 
#include <iostream>
#include "BelotTournament.h"
#include "Person.h"
#include "Team.h"
#include <cmath> 
void makeOneTeam(Person* oneTeamHolder)
{
    for (int i = 0; i < 2; i++)
    {
        char nameBuffer[100];
        char positionBuffer[100];
        int salary;

        
        std::cout << "Enter name for player " << i + 1 << ": " << std::endl;
        std::cin.getline(nameBuffer, 100);

        std::cout << "Enter position for player " << i + 1 << ": " << std::endl;;
        std::cin.getline(positionBuffer, 100);

        std::cout << "Enter salary for player " << i + 1 << ": " << std::endl;;
        std::cin >> salary;
        std::cin.ignore();

        char* name = new char[std::strlen(nameBuffer) + 1];
        std::strcpy(name, nameBuffer);

        char* position = new char[std::strlen(positionBuffer) + 1];
        std::strcpy(position, positionBuffer);

        oneTeamHolder[i] = Person(name, position, salary);
        delete[] name;
        delete[] position;
    }
    

}
void makeTeams(unsigned int amount, Team* teams)
{
    for (int i = 0; i < amount; i++)
    {
        std::cout << "Team " << i << std::endl;
        Person* oneTeamHolder = new Person[2];
        makeOneTeam(oneTeamHolder);
   
        teams[i] = Team(oneTeamHolder, false);
        delete[] oneTeamHolder;

    }
}
int main()
{
    unsigned int amount;
    std::cout << "Amount of programers joining: \n";
    std::cin >> amount;
    std::cin.ignore();

    Team* teams = new Team[amount/2];
    makeTeams(amount/2, teams);

    BelotTournament tournament(teams, amount / 2, 0);
    tournament.startTournament();

    std::cout << "Total money: " << tournament.getCharityMoney() << std::endl;
    delete[] teams;

}

