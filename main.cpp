#include <iostream>
#include "AVLTree.h"
#include "sortingTreeMethods.h"
#include "Player.h"
#include <memory>

//int main1(){
//    int val;
//    AVLTree<int, SortRegular> tree;
//    std::cout << "enter values" << std::endl;
//    tree.insert(12);
//    tree.printD(tree.getRoot(), 0);
//    tree.printH(tree.getRoot(), 0);
//    tree.insert(15);
//    tree.printD(tree.getRoot(), 0);
//    tree.printH(tree.getRoot(), 0);
//    return 0;
//}

int main2(){
    AVLTree<Player*, SortByScore> tree;
    auto p1 = std::make_shared<Player>(12, 1, 0, 0, 7, true);
    tree.insert(p1);
    tree.printD(tree.getRoot(), 0);
    tree.printH(tree.getRoot(), 0);

    Player *p2 = new Player(15, 1, 2, 0, 6, true);
    tree.insert(p2);
    tree.printD(tree.getRoot(), 0);
    tree.printH(tree.getRoot(), 0);
    return 0;
}

int main() {
    main2();
    return 0;
}


//std::cout << "enter values" << std::endl;
//for(int i=0; i<7; i++){
//std::cin >> val;
//tree.insert(val);
//tree.printD(tree.getRoot(), 0);
//tree.printH(tree.getRoot(), 0);
//std::cout << "---------------";
//}
//
//
//std::cout << "enter values to delete" << std::endl;
//for(int i=0; i<7; i++){
//std::cin >> val;
//tree.remove(val);
//tree.printD(tree.getRoot(), 0);
//tree.printH(tree.getRoot(), 0);
//std::cout << "---------------";
//}