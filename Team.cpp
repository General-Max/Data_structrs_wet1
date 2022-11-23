#include "Team.h"

Team::Team(int teamId, int points) : m_teamId(teamId),m_points(points),m_topScorer(nullptr)
{
    m_playedTogether=0;
    m_totalPlayers=0;
    m_totalGoals=0;
    m_totalCards=0;
}

int Team::getTeamId()
{
    return this->m_teamId;
}
int Team::getPoints()
{
    return this->m_points;
}
int Team::getPlayedTogether()
{
    return this->m_playedTogether;
}
Player* Team::getTopScorer()
{
    return this->m_topScorer;
}
int Team::getTotalPlayers()
{
    return this->m_totalPlayers;
}
int Team::getTotalGoals()
{
    return this->m_totalGoals;
}
int Team::getTotalCards()
{
    return this->m_totalCards;
}