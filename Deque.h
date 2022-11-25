
#ifndef EX1_DEQUE_H
#define EX1_DEQUE_H

#include "DoubleNode.h"

template<class T>
class Deque
{
private:
    DoubleNode<T>* m_front;
    DoubleNode<T>* m_rear;
    int m_size;

public:
    Deque();
    ~Deque();
    void insertFront(const T& data);
    void insertRear(const T& data);
    T* getFront();
    T* getRear();
    void setFront(const DoubleNode<T>* node);
    void setRear(const DoubleNode<T>* node);
    int size();
    bool isEmpty();
};


template<class T>
Deque<T>::Deque()
{
    this->m_front=nullptr;
    this->m_rear=nullptr;
    this->m_size=0;
}

template<class T>
Deque<T>::~Deque()
{
    if this==nullptr{
        return;
    }
    for(int i=0;i<this->m_size;i++){
        this->m_front=this->m_front->getPrev();
        delete this->m_front->getNext();
    }
    
}

template<class T>
void Deque<T>::insertFront(const T& node)
{
    this->m_front->setNext(node);
    this->m_front=this->m_front->getNext();
}

template<class T>
void Deque<T>::insertRear(const T& node)
{
    this->m_rear->setPrev(node);
    this->m_front=this->m_front->getPrev();
}

template<class T>
T* Deque<T>::getFront()
{
    return this->m_front;
}
template<class T>
T* Deque<T>::getRear()
{
    return this->m_rear;
}
template<class T>
void Deque<T>::setFront(const DoubleNode<T>* node)
{
    this->m_front = node;
}
template<class T>
void Deque<T>::setRear(const DoubleNode<T>* node)
{
    this->m_rear = node;
}
template<class T>
int Deque<T>::size()
{
    return this->m_size;
}
template<class T>
bool Deque<T>::isEmpty()
{
    return this->m_size == 0;
}

#endif //EX1_DEQUE_H
