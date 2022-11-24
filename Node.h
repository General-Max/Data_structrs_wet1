
#ifndef EX1_NODE_H
#define EX1_NODE_H

template<class T>
class Node
{
private:
    T *m_data;
public:  
    // Default constructor
    Node();
    // Parameterised Constructor
    explicit Node(T *data);
    ~Node();
    
    T* getData();
     

};

template<class T>
Node<T>::Node()
{
    this->m_data = nullptr;
}
  
    // Parameterised Constructor
template<class T>
Node<T>::Node(T* data): m_data(data)
{};

template <class T>
Node<T>::~Node()
{
    delete this->m_data;
}

template<class T>
T* Node<T>::getData()
{
    return this->m_data;
}

#endif //EX1_NODE_H
