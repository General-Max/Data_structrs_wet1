#include "Team.h"

Team::Team(int teamId, int points) : m_teamId(teamId),m_points(points),m_topScorer(nullptr)
{
    m_playedToghether=0;
    m_totalPlayers=0;
    m_totalGoals=0;
    m_totalCards=0;
}