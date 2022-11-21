//
// Created by User on 17/11/2022.
//

#ifndef UNTITLED6_AVLTREE_H
#define UNTITLED6_AVLTREE_H

#include <iostream>
#include "nodeTree.h"

class AVLTree{
public:
    AVLTree();
    Node* getRoot();
    void setRoot(Node* newNode);
    Node* insertNode(Node* current, Node* newNode);
    int getBalanceFactor(Node* node);
    Node* rightRotate(Node* nodeA);
    Node* leftRotate(Node* nodeA);

private:
    Node *m_root;
};
void print2D(Node *node, int space);
void printH(Node *node, int space);

#endif //UNTITLED6_AVLTREE_H
