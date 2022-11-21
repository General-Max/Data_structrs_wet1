//
// Created by User on 17/11/2022.
//

#include "AVLtree.h"

AVLTree:: AVLTree() : m_root(NULL){};

Node* AVLTree::getRoot() {
    return m_root;
}

void AVLTree::setRoot(Node *newNode) {
    m_root = newNode;
}

int nodeHeight(Node* node){
    if(node == NULL)
        return -1;
    return node->getHeight();
}

int AVLTree::getBalanceFactor(Node* node){
    if(node == NULL)
        return -1;
    return (nodeHeight(node->getLeft()) - nodeHeight(node->getRight()));
}

Node* AVLTree::rightRotate(Node* nodeA){
    Node* leftSubTree = nodeA->getLeft();
    Node* leftRightSubTree = leftSubTree->getRight();
    leftSubTree->setRight(nodeA);
    nodeA->setLeft(leftRightSubTree);
    return leftSubTree;
}

Node* AVLTree::leftRotate(Node* nodeA){
    Node* rightSubTree = nodeA->getRight();
    Node* rightLeftSubTree = rightSubTree->getLeft();
    rightSubTree->setLeft(nodeA);
    nodeA->setRight(rightLeftSubTree);
    return rightSubTree;
}

Node* AVLTree::insertNode(Node* current, Node *newNode) {
    if(current==NULL){
        current = newNode;
        return current;
    }
    if(newNode->getValue() < current->getValue()){
        current->setLeft(insertNode(current->getLeft(), newNode));
    }
    else if(newNode->getValue() > current->getValue()){
        current->setRight(insertNode(current->getRight(), newNode));
    }
    else{
        std::cout << "error inserting a duplicated num";
    }

    current->updateHeight();

    int balanceFactor = getBalanceFactor(current);
    int leftBalanceFactor = getBalanceFactor(current->getLeft());
    int rightBalanceFactor = getBalanceFactor(current->getRight());

    Node* toReturn = current;
    // Left-Left imbalance
    if(balanceFactor > 1 && leftBalanceFactor > -1){
        toReturn = rightRotate(current);
    }

    // Right-Right imbalance
    else if(balanceFactor < -1 && rightBalanceFactor < 1){
        toReturn = leftRotate(current);
    }

    // Left-Right imbalance
    else if(balanceFactor > 1 && leftBalanceFactor == -1){
        current->setLeft(leftRotate(current->getLeft()));
        toReturn = rightRotate(current);
    }

    // Right-Left imbalance
    else if(balanceFactor < -1 && leftBalanceFactor == 1){
        current->setRight(rightRotate(current->getRight()));
        toReturn = leftRotate(current);
    }

    current->updateHeight();

    return toReturn;
}

void print2D(Node *node, int space){
    if(node==NULL)
        return;
    space += 10;
    print2D(node->getRight(), space);
    std::cout << std::endl;
    for(int i= 10; i<space; i++){
        std::cout << " ";
    }
    std::cout << node->getValue() << "\n";
    print2D(node->getLeft(), space);
}

void printH(Node *node, int space){
    if(node==NULL)
        return;
    space += 10;
    printH(node->getRight(), space);
    std::cout << std::endl;
    std::cout << node->getValue() << ": "<< node->getHeight() << "\n";
    printH(node->getLeft(), space);
}
