#include <iostream>
#include "AVLTree.h"

int main() {
    int val;
    AVLTree<int> tree;
    std::cout << "enter values" << std::endl;
    for(int i=0; i<7; i++){
        std::cin >> val;
        tree.insert(val);
        tree.printD(tree.getRoot(), 0);
        tree.printH(tree.getRoot(), 0);
        std::cout << "---------------";
    }


    std::cout << "enter values to delete" << std::endl;
    for(int i=0; i<7; i++){
        std::cin >> val;
        tree.remove(val);
        tree.printD(tree.getRoot(), 0);
        tree.printH(tree.getRoot(), 0);
        std::cout << "---------------";
    }
    return 0;
}
