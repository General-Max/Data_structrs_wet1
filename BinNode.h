
#ifndef EX1_BINNODE_H
#define EX1_BINNODE_H

#include "Node.h"

template<class T>
class BinNode : public Node<T>
{
private:
    Node<T> *m_right;
    Node<T> *m_left;
    Node<T> *m_father;
    int m_height;

public:
    BinNode(const T& value);
    ~BinNode();
    BinNode<T> getLeft();
    BinNode<T> getRight();
    BinNode<T> getFather();
    int getHeight();

    void setLeft();
    void setRight();
    void setFather();
    void setHeight();

};

template<class T>
BinNode<T>::BinNode(const T& value): m_data(value)
{
    this->m_father=nullptr;
    this->m_left=nullptr;
    this->m_right=nullptr;
    this->height=0
}

template<class T>
BinNode<T>::~BinNode()
{
    delete this->m_data;
}

template <class T>
BinNode<T> getLeft()
{
    return this->m_left;
}

template <class T>
BinNode<T> getRight()
{
    return this->m_right;
}

template <class T>
BinNode<T> getFather()
{
    return this->m_father;
}

template <class T>
int getHeight()
{
    return this->m_height;
}

template <class T>
void setLeft(T* newLeft)
{
    this->m_left = newLeft;
}

template <class T>
void setRight(T* newRight)
{
    this->m_right=newRight;
}

template <class T>
void setFather(T* newFather)
{
    this->m_father = newFather;
}

template <class T>
void setHeight(int newHeight)
{
    this->m_height = newHeight;
}

#endif //EX1_BINNODE_H

