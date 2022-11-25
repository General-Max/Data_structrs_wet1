#include "playerNodeWithListPointer.h"

PlayerNodeWithListPointer::PlayerNodeWithListPointer(Player* player): BinNode<Player *>(player), m_positionInList(nullptr){}

PlayerNodeWithListPointer::~PlayerNodeWithListPointer(){
    delete this->m_positionInList;
}

ListNode<Player*>* PlayerNodeWithListPointer::getPositionInList()
{
    return this->m_positionInList;
}

void PlayerNodeWithListPointer::setPositionInList(ListNode<Player*>* newPosition)
{
    this->m_positionInList = newPosition;
}

