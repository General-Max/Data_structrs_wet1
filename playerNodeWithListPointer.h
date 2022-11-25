//
// Created by User on 25/11/2022.
//

#ifndef DATA_STRUCTRS_WET1_PLAYERSBYSCORENODEE_H
#define DATA_STRUCTRS_WET1_PLAYERSBYSCORENODEE_H
#include "BinNode.h"
#include "Player.h"
#include "listNode.h"

class PlayerNodeWithListPointer : public BinNode<Player*>{
private:
    ListNode<Player*>* m_positionInList;
public:
    PlayerNodeWithListPointer(Player* player);
    ~PlayerNodeWithListPointer();

    ListNode<Player*>* getPositionInList();
    void setPositionInList(ListNode<Player*>* newPosition);

};

#endif //DATA_STRUCTRS_WET1_PLAYERSBYSCORENODEE_H
