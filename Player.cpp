#include "Player.h"

Player::Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalkeeper) : m_playerId(playerId),
m_teamId(teamId), m_gamesPlayed(gamesPlayed), m_goals(goals), m_cards(cards), m_goalKeeper(goalkeeper){}

int Player::getPlayerId() const {
    return m_playerId;
}

int Player::getTeamId() const {
    return m_teamId;
}

int Player::getGamesPlayed() const {
    return m_gamesPlayed;
}

int Player::getGoals() const {
    return m_goals;
}

bool Player::getGoalKeeper() const {
    return m_goalKeeper;
}

int Player::getCards() const {
    return m_cards;
}

ostream& operator<<(ostream& os, const Player& player)
{
    os << "player id: " <<  player.getPlayerId() << ", goals: " << player.getGoals() << ", cards: "
    << player.getCards();
    return os;
}



