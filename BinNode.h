
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

    void setLeft(const T& newLeft);
    void setRight(const T& newRight);
    void setFather(const T& newFather);
    void setHeight(int newHeight);

};

template<class T>
BinNode<T>::BinNode(const T& value): Node<T>(value), m_father(nullptr), m_left(nullptr), m_right(nullptr),
        m_height(0){ }

template<class T>
BinNode<T>::~BinNode()
{
    delete this->m_data;
}

template <class T>
BinNode<T> BinNode<T>::getLeft()
{
    return this->m_left;
}

template <class T>
BinNode<T> BinNode<T>::getRight()
{
    return this->m_right;
}

template <class T>
BinNode<T> BinNode<T>::getFather()
{
    return this->m_father;
}

template <class T>
int BinNode<T>::getHeight()
{
    return this->m_height;
}

template <class T>
void BinNode<T>::setLeft(const T& newLeft)
{
    this->m_left = newLeft;
}

template <class T>
void BinNode<T>::setRight(const T& newRight)
{
    this->m_right=newRight;
}

template <class T>
void BinNode<T>::setFather(const T& newFather)
{
    this->m_father = newFather;
}

template <class T>
void BinNode<T>::setHeight(int newHeight)
{
    this->m_height = newHeight;
}

#endif //EX1_BINNODE_H

