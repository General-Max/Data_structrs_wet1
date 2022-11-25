
#ifndef EX1_DOUBLENODE_H
#define EX1_DOUBLENODE_H

#include "Node.h"

template<class T>
class DoubleNode : public Node<T>
{
private:
    Node<T> *m_next;
    Node<T> *m_prev;

public:
    DoubleNode(const T& value);
    ~DoubleNode();
    DoubleNode<T> getNext();
    DoubleNode<T> getPrev();

    void setNext(const T& next);
    void setPrev(const T& prev);

};

template<class T>
DoubleNode<T>::~DoubleNode()
{
    delete this->m_data;
}

template <class T>
DoubleNode<T> DoubleNode<T>::getNext()
{
    return this->m_next;
}

template<class T>
void DoubleNode<T>::setNext(const T& next)
{
    this->m_next=next;
}

template<class T>
void DoubleNode<T>::setPrev(const T& prev)
{
    this->m_prev=prev;
}


#endif //EX1_DOUBLENODE_H

