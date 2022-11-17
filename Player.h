#ifndef EX1_Player_H
#define EX1_Player_H

class Player{
public:
    Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalkeeper); // check for consts
    ~Player() = default;

private:
    int playerId;
    int teamId;
    int gamesPlayed;
    int goals;
    int cards;
    bool goalKeeper;
};

#endif