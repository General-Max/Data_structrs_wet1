//
// Created by User on 21/11/2022.
//


#include "nodeTree.h"
#include <iostream>

Node::Node():value(0), right(NULL), left(NULL), height(0){}

int Node::getValue() const {
    return value;
}

Node* Node::getRight(){
    return right;
}

Node* Node::getLeft(){
    return left;
}

void Node::setValue(int newValue){
    value = newValue;
}
void Node::setRight(Node* newNode) {
    right= newNode;
}

void Node::setLeft(Node *newNode) {
    left = newNode;
}

int Node::getHeight() const {
    return height;
}

void Node::setHeight(int newHeight) {
    height = newHeight;
}

