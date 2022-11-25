//
// Created by User on 25/11/2022.
//

#ifndef DATA_STRUCTRS_WET1_PLAYERSBYIDNODE_H
#define DATA_STRUCTRS_WET1_PLAYERSBYIDNODE_H

#include "BinNode.h"
#include "Team.h"
#include "Player.h"
#include "listNode.h"

class PlayersByIdNode : public BinNode<Player*>{
private:
    BinNode<Team*>* m_playerTeamPointer;
public:
    PlayersByIdNode(Player* player, BinNode<Team*>* playerTeam);
    ~PlayersByIdNode();

    BinNode<Team*>* getPlayerTeamPointer();
    void setPlayerTeamPointer(BinNode<Team*>* playerTeam);
};

#endif //DATA_STRUCTRS_WET1_PLAYERSBYIDNODE_H
