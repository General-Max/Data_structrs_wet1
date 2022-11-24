
#ifndef EX1_BINNODE_H
#define EX1_BINNODE_H

#include "Node.h"

template<class T>
class BinNode : public Node
{
private:
    Node<T> *m_right;
    Node<T> *m_left;
    Node<T> *m_father;
    int m_height;

public:
    BinNode();
    ~BinNode();
};

template<class T>
BinNode<T>::BinNode()
{

}

template<class T>
BinNode<T>::~BinNode()
{

}

#endif //EX1_BINNODE_H

