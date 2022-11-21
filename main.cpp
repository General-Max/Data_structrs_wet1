#include <iostream>
#include "AVLtree.h"

int main() {
    AVLTree tree;
    Node* newNode;
    int val;
    std::cout << "enter values" << std::endl;
    for(int i=0; i<10; i++){
        std::cin >> val;
        newNode = new Node();
        newNode->setValue(val);
        tree.setRoot(tree.insertNode(tree.getRoot(), newNode));
        print2D(tree.getRoot(), 0);
        printH(tree.getRoot(), 0);
        std::cout << "---------------";
    }
    return 0;
}
