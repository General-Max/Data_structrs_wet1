
#ifndef EX1_Team_H
#define EX1_Team_H

#include "Player.h"

class Team{
    public:
        Team(int teamId, int points);
        ~Team() = default;
    
    private:
        int m_teamId;
        int m_points;
        int m_playedToghether;
        Player* m_topScorer;
        int m_totalPlayers;
        int m_totalGoals;
        int m_totalCards;
        //AVLTree<Player*> playersByID
        //AVLTree<Player*> playersByGoals(and their order)
};

#endif //EX1_Team_H
