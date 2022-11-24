
#ifndef EX1_NODE_H
#define EX1_NODE_H

template<class T>
class Node {
private:
    T data;
    Node* next;
public:  
    // Default constructor
    Node();
    // Parameterised Constructor
    Node(T data);
};

template<class T>
Node<T>::Node()
{
    T = nullptr;
    next = NULL;
}
  
    // Parameterised Constructor
template<class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}


#endif //EX1_NODE_H
