//
// Created by User on 23/11/2022.
//

#ifndef DATA_STRUCTRS_WET1_SORTINGTREEMETHODS_H
#define DATA_STRUCTRS_WET1_SORTINGTREEMETHODS_H

#include "Player.h"
#include "Team.h"

class SortRegular{
public:
    SortRegular() = default;
    ~SortRegular() = default;
    static bool equalTo(int n1, int n2);

    //static bool greaterThan(int id1, int id2);

    static bool lessThan(int n1, int n2);
};


class SortById{
public:
    SortById() = default;
    ~SortById() = default;
    static bool equalTo(Player* player1, Player* player2);

    static bool lessThan(Player* player1, Player* player2);

    static bool equalTo(Player* player1, int otherId);

    static bool lessThan(Player* player1, int otherId);
};

class SortByScore{
public:
    SortByScore() = default;
    ~SortByScore() = default;

    static bool equalTo(Player* player1, Player* player2);

    static bool lessThan(Player* player1, Player* player2);

    static bool equalTo(Player* player1, int otherGoals);

    static bool lessThan(Player* player1, int otherGoals);
};

class SortTeamById{
public:
    SortTeamById() = default;
    ~SortTeamById() = default;

    static bool equalTo(Team* team1, Team* team2);

    static bool equalTo(Team* team1, int otherId);

    static bool lessThan(Team* team1, Team* team2);

    static bool lessThan(Team* team1, int otherId);
};


#endif //DATA_STRUCTRS_WET1_SORTINGTREEMETHODS_H
