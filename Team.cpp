#include "Team.h"

Team::Team(int teamId, int points) : m_teamId(teamId),m_points(points),m_topScorer(nullptr)
{
    m_playedTogether=0;
    m_totalPlayers=0;
    m_totalGoals=0;
    m_totalCards=0;
}

int Team::getTeamId() const
{
    return this->m_teamId;
}
int Team::getPoints() const
{
    return this->m_points;
}
int Team::getPlayedTogether() const
{
    return this->m_playedTogether;
}
Player* Team::getTopScorer() const
{
    return this->m_topScorer;
}
int Team::getTotalPlayers() const
{
    return this->m_totalPlayers;
}
int Team::getTotalGoals() const
{
    return this->m_totalGoals;
}
int Team::getTotalCards() const
{
    return this->m_totalCards;
}

void Team::setPlayedTogether(int playedTogether)
{
    this->m_playedTogether = playedTogether;
}
void Team::setTopScorer(Player* topScorer)
{
    this->m_topScorer=topScorer;
}
void Team::setTotalPlayers(int totalPlayers)
{
    this->m_totalPlayers = totalPlayers;
}
void Team::setTotalGoals(int totalGoals)
{
    this->m_totalGoals = totalGoals;
}
void Team::setTotalCards(int totalCards)
{
    this->m_totalCards = totalCards;
}