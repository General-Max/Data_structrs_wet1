#include "sortingTreeMethods.h"
#include <iostream>

// sort by id implementation
bool SortById::equalTo(Player* player1, Player* player2){
    return player1->getPlayerId()==player2->getPlayerId();
}

bool SortById::lessThan(Player* player1, Player* player2){
    return player1->getPlayerId() < player2->getPlayerId();
}

bool SortById::equalTo(Player *player1, int otherId) {
    return player1->getPlayerId()==otherId;
}

bool SortById::lessThan(Player* player1, int otherId){
    return player1->getPlayerId() < otherId;
}


 // sort by score implementation
bool SortByScore::equalTo(Player *player1, Player *player2) {
    return player1->getPlayerId()==player2->getPlayerId();
}

bool SortByScore::lessThan(Player *player1, Player *player2) {
    if(player1->getGoals() < player2->getGoals()){
        return true;
    }
    else if(player1->getGoals() > player2->getGoals()){
        return false;
    }

    // in case both players have the same number of goals
    if(player1->getCards() > player2->getCards()){
        return true;
    }
    else if(player1->getCards() < player2->getCards()){
        return false;
    }

    // in case both players have the same number of cards
    if(player1->getPlayerId() < player2->getPlayerId()){
        return true;
    }
    return false;
}

bool SortByScore::equalTo(Player *player1, int otherGoals) {
    return player1->getGoals() == otherGoals;
}

bool SortByScore::lessThan(Player *player1, int otherGoals) {
    return player1->getGoals() < otherGoals;
}

bool SortRegular::equalTo(int n1, int n2) {
    return n1==n2;
}

bool SortRegular::lessThan(int n1, int n2) {
    return n1 < n2;
}


// sort team by its id
bool SortTeamById::equalTo(Team* team1, Team* team2){
    return team1->getTeamId()==team2->getTeamId();
}

bool SortTeamById::equalTo(Team *team1, int otherId) {
    return team1->getTeamId()==otherId;
}

bool SortTeamById::lessThan(Team* team1, Team* team2){
    return team1->getTeamId() < team2->getTeamId();
}

bool SortTeamById::lessThan(Team* team1, int otherId){
    return team1->getTeamId() < otherId;
}

