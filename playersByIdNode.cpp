#include "playersByIdNode.h"

PlayersByIdNode::PlayersByIdNode(Player* player, BinNode<Team*>* playerTeam): BinNode<Player *>(player),
        m_playerTeamPointer(playerTeam) {}

PlayersByIdNode::~PlayersByIdNode()
{
    delete this->m_playerTeamPointer;
}

BinNode<Team*>* PlayersByIdNode::getPlayerTeamPointer()
{
    return this->m_playerTeamPointer;
}

void PlayersByIdNode::setPlayerTeamPointer(BinNode<Team *> *playerTeam)
{
    this->m_playerTeamPointer = playerTeam;
}
