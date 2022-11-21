//
// Created by User on 21/11/2022.
//


#include "nodeTree.h"
#include <iostream>

Node::Node():m_value(0), m_right(NULL), m_left(NULL), m_height(0){}

int Node::getValue() const {
    return m_value;
}

Node* Node::getRight(){
    return m_right;
}

Node* Node::getLeft(){
    return m_left;
}

void Node::setValue(int newValue){
    m_value = newValue;
}
void Node::setRight(Node* newNode) {
    m_right= newNode;
}

void Node::setLeft(Node *newNode) {
    m_left = newNode;
}

int Node::getHeight() const {
    return m_height;
}

void Node::setHeight(int newHeight) {
    m_height = newHeight;
}

void Node::updateHeight() {
    if (nodeHeight(this->getRight()) > nodeHeight(this->getLeft()))
        m_height = nodeHeight(this->getRight())+1;
    else
        m_height = nodeHeight(this->getLeft())+1;
}