#include <iostream>
#include "AVLTree.h"
#include "sortingTreeMethods.h"
#include "Player.h"
#include <memory>
#include "Node.h"

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

int main3(){
    auto p1 = new Player(12, 1, 0, 0, 7, true);
    Node<Player*> n1 = Node<Player*>(p1);
    Node<Player*> n2 = Node<Player*>(p1);
    std::cout << **n1.getData() << std::endl;
    std::cout << **n2.getData() << std::endl;

    p1->updateGoals(5);
    std::cout << **n1.getData() << std::endl;
    std::cout << **n2.getData() << std::endl;
    std::cout << *p1 << std::endl;

    return 0;
}

int main2(){
    AVLTree<Player*, SortByScore> tree;
   // auto p1 = std::make_shared<Player>(12, 1, 0, 0, 7, true);
    auto p1 = new Player(12, 1, 0, 0, 7, true);
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
    main3();
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