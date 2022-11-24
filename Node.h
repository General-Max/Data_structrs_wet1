
#ifndef EX1_NODE_H
#define EX1_NODE_H

template<class T>
class Node {
private:
    T *data;
public:  
    // Default constructor
    Node();
    // Parameterised Constructor
    explicit Node(const T& data);
};

template<class T>
Node<T>::Node()
{
    data = nullptr;
}
  
    // Parameterised Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
}

#endif //EX1_NODE_H
