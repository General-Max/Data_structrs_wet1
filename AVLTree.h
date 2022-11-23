//
// Created by User on 22/11/2022.
//

#ifndef EX1_AVLTREE_H
#define EX1_AVLTREE_H
#include <iostream>

template<class T, class Comparison>
class AVLTree {
private:
    // Tree fields
    struct Node {
        Node *m_right;
        Node *m_left;
        Node *m_father;
        int m_height;
        T *m_value;
    };
    Node *m_root;
    Node *m_minValueNode; // in order to find the minimum value in tree in O(1)
    Node *m_maxValueNode; // in order to find the maximum value in tree in O(1)
    int m_size;
    Comparison comparisonFunction;

    // Node Functions
    Node *initNode(const T &value);

    Node *balanceTree(Node *node);

    Node *insertNode(Node *newNode, Node *currentNode, Node *father);

    Node *findNode(Node *node, const T &value);

    Node *removeNode(Node *currentNode, Node *nodeToDelete);

    int getBalanceFactor(Node *node) const;

    int height(const Node *node) const;

    int findNewHeight(const Node* node) const;

    T *getNodeValue(Node *node) const;

    // Rotation Functions
    Node *leftLeftRotation(Node *node);

    Node *leftRightRotation(Node *node);

    Node *rightLeftRotation(Node *node);

    Node *rightRightRotation(Node *node);

    // Constructor, Destructor helper functions
    Node* copyNode(Node* node);

    void empty_aux(Node* node);

    Node* findMin(AVLTree<T, Comparison>::Node* node) const;

    Node* findMax(AVLTree<T, Comparison>::Node* node) const;

    T* getMinValueInTree() const;

    T* getMaxValueInTree() const;


public:
    // Constructors, Destructor, Assignment
    AVLTree();

    AVLTree(const AVLTree<T, Comparison> &tree);

    AVLTree &operator=(const AVLTree<T, Comparison> &tree);

    ~AVLTree();

    // Interface Functions
    void insert(const T &value);

    T *find(const T &value);

    void remove(const T &value);

    int getHeight() const;

    int getSize() const;

    Node* getRoot() const;

    void emptyTree();

    bool isEmpty() const;

    void printH(Node *node, int space);

    void printD(Node *node, int space);
};

template<class T, class Comparison>
AVLTree<T, Comparison>::AVLTree() : m_root(NULL), m_minValueNode(NULL), m_maxValueNode(NULL), m_size(0) {
}

template<class T, class Comparison>
AVLTree<T, Comparison>::~AVLTree(){
    emptyTree();
}

template<class T, class Comparison>
AVLTree<T, Comparison>& AVLTree<T, Comparison>::operator=(const AVLTree<T, Comparison> &tree){
    // TODO: ADD CHECK IF SUCCEED BEFORE EMPTY
    if(&tree == this){
        return *this;
    }
    emptyTree();
    m_root = copyNode(tree.getRoot());
    m_minValueNode = findMin(m_root);
    m_maxValueNode = findMax(m_root);
    m_size = tree.getSize();
    return *this;
}

template<class T, class Comparison>
AVLTree<T, Comparison>::AVLTree(const AVLTree<T, Comparison>& tree):m_root(NULL), m_minValueNode(NULL), m_maxValueNode(NULL),
            m_size(tree.getSize()){
    // todo: check if can be added to the comprehension list
    m_root = copyNode(tree.getRoot());
    m_minValueNode = findMin(m_root);
    m_maxValueNode = findMax(m_root);
}


template<class T, class Comparison>
void AVLTree<T, Comparison>::insert(const T& value) {
    if (&value == NULL) {
        return;
    }
    if (findNode(m_root, value) != NULL) {
        std::cout << "throw NodeExists()";
    }

    Node *node = initNode(value);

    m_root = insertNode(node, m_root, NULL);
    // update minimum and maximum tree nodes
    m_minValueNode = findMin(m_root);
    m_maxValueNode = findMax(m_root);
    m_size++;
}

template<class T, class Comparison>
T* AVLTree<T, Comparison>::find(const T& value){
    Node* node = findNode(m_root, value);
    if(node == NULL)
        std::cout << "throw NodeDoesntExist()";
    return node->data;
}

template<class T, class Comparison>
void AVLTree<T, Comparison>::remove(const T& value) {
    if (isEmpty() || &value == NULL) {
        return;
    }
    Node* node_to_remove = findNode(m_root, value);

    if (node_to_remove == NULL) {
        std::cout << "throw NodeDoesntExist()";
    }

    m_root = removeNode(node_to_remove, m_root);
    // update minimum and maximum tree nodes
    m_minValueNode = findMin(m_root);
    m_maxValueNode = findMax(m_root);
    m_size--;
}
template<class T, class Comparison>
void AVLTree<T, Comparison>::empty_aux(AVLTree<T, Comparison>::Node* node) {
    if(node == NULL){
        return;
    }

    if(node->m_left){
        empty_aux(node->m_left);
    }
    if(node->m_right){
        empty_aux(node->m_right);
    }
    delete node->m_value;
    delete node;
}

template<class T, class Comparison>
void AVLTree<T, Comparison>::emptyTree() {
    if(m_size > 0){
        empty_aux(m_root);
        m_root = NULL;
        m_minValueNode = NULL;
        m_maxValueNode = NULL;
        m_size = 0;
    }
}

template<class T, class Comparison>
int AVLTree<T, Comparison>::getHeight()const{
    if (m_root == NULL) {
        return 0;
    }
    return m_root->m_height;
}

template<class T, class Comparison>
int AVLTree<T, Comparison>::getSize() const{
    return m_size;
}

template<class T, class Comparison>
bool AVLTree<T, Comparison>::isEmpty() const{
    return m_size == 0;
}

template <class T, class Comparison>
void AVLTree<T, Comparison>::printD(Node *node, int space){
    if(node==NULL)
        return;
    space += 10;
    printD(node->m_right, space);
    std::cout << std::endl;
    for(int i= 10; i<space; i++){
        std::cout << " ";
    }
    std::cout << **node->m_value << "\n";
    printD(node->m_left, space);
}

template <class T, class Comparison>
void AVLTree<T, Comparison>::printH(Node *node, int space){
    if(node==NULL)
        return;
    space += 10;
    printH(node->m_right, space);
    std::cout << std::endl;
    std::cout << **node->m_value << ": "<< node->m_height << "\n";
    printH(node->m_left, space);
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::getRoot() const {
    return m_root;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::initNode(const T &value) {
    Node* node = new Node;
    node->m_value = new T(value);
    node->m_height = 0;
    node->m_left = NULL;
    node->m_right = NULL;
    node->m_father = NULL;
    return node;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::balanceTree(AVLTree<T, Comparison>::Node *node) {
    int balanceFactor = getBalanceFactor(node);
    int leftBalanceFactor = getBalanceFactor(node->m_left);
    int rightBalanceFactor = getBalanceFactor(node->m_right);

    // Left-Left imbalance
    if(balanceFactor > 1 && leftBalanceFactor > -1){
        return leftLeftRotation(node);
    }

        // Right-Right imbalance
    else if(balanceFactor < -1 && rightBalanceFactor < 1){
        return rightRightRotation(node);
    }

        // Left-Right imbalance
    else if(balanceFactor > 1 && leftBalanceFactor == -1){
        return leftRightRotation(node);
    }

        // Right-Left imbalance
    else if(balanceFactor < -1 && rightBalanceFactor == 1){
        return rightLeftRotation(node);
    }

    node->m_height = findNewHeight(node);
    return node;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::insertNode(AVLTree<T, Comparison>::Node  *newNode,
                                                                          AVLTree<T, Comparison>::Node  *currentNode,
                                                                          AVLTree<T, Comparison>::Node  *father){
    if (currentNode == NULL) {
        newNode->m_father = father;
        return newNode;
    }
    if(comparisonFunction.lessThan(*newNode->m_value, *currentNode->m_value)){
        currentNode->m_left = insertNode(newNode, currentNode->m_left, currentNode);
    } else {
        currentNode->m_right = insertNode(newNode, currentNode->m_right, currentNode);
    }
    return balanceTree(currentNode);
}

template<class T, class Comparison>
int AVLTree<T, Comparison>::findNewHeight(const AVLTree<T, Comparison>::Node *node) const {
    if(height(node->m_right) > height(node->m_left)){
        return height(node->m_right)+1;
    }
    return height(node->m_left)+1;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::findNode(AVLTree<T, Comparison>::Node *node, const T &value) {
    if(node == NULL)
        return NULL;
    if (comparisonFunction.equalTo(value, *node->m_value)) {
        return node;
    } else {
        if(comparisonFunction.lessThan(*node->m_value, value)){
            return findNode(node->m_right, value);
        } else {
            return findNode(node->m_left, value);
        }
    }
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::removeNode(AVLTree<T, Comparison>::Node *currentNode,
                                                                          AVLTree<T, Comparison>::Node *nodeToDelete){
    if (currentNode == NULL) {
        return NULL;
    }
    // Delete the node
    if (*currentNode->m_value == *nodeToDelete->m_value) {
        if (!nodeToDelete->m_right && !nodeToDelete->m_left) {
            // Leaf
            delete nodeToDelete->m_value;
            delete nodeToDelete;
            return NULL;
        } else if (!nodeToDelete->m_right) {
            // Only left son
            Node* temp = nodeToDelete->m_left;
            delete nodeToDelete->m_value;
            nodeToDelete->m_value = new T(*temp->m_value);
            nodeToDelete->m_left = removeNode(nodeToDelete, nodeToDelete->m_left);

        } else if (!nodeToDelete->m_left) {
            // Only right son
            Node* temp = nodeToDelete->m_right;
            delete nodeToDelete->m_value;
            nodeToDelete->m_value = new T(*temp->m_value);
            nodeToDelete->m_right = removeNode(nodeToDelete, nodeToDelete->m_right);
        } else {
            // right and left son exist
            Node *temp = findMin(nodeToDelete->m_right);
            delete nodeToDelete->m_value;
            nodeToDelete->m_value = new T(*temp->m_value);
            nodeToDelete->m_right = removeNode(nodeToDelete, nodeToDelete->m_right);
        }
    } else if (comparisonFunction.lessThan(*currentNode->m_value, *nodeToDelete->m_value)) {
        nodeToDelete->m_left = removeNode(currentNode, nodeToDelete->m_left);
    } else {
        nodeToDelete->m_right = removeNode(currentNode, nodeToDelete->m_right);
    }

    nodeToDelete->m_height = findNewHeight(nodeToDelete);

    // Balancing the tree
    return balanceTree(nodeToDelete);
}

template<class T, class Comparison>
int AVLTree<T, Comparison>::getBalanceFactor(AVLTree<T, Comparison>::Node *node) const {
    return node == NULL ? -1 : (height(node->m_left) - height(node->m_right));
}

template<class T, class Comparison>
int AVLTree<T, Comparison>::height(const AVLTree<T, Comparison>::Node* node) const{
    return node == NULL ? -1 : node->m_height;
}

template<class T, class Comparison>
T *AVLTree<T, Comparison>::getNodeValue(AVLTree<T, Comparison>::Node *node) const {
    return node->m_value;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::leftLeftRotation(AVLTree<T, Comparison>::Node *node) {
    Node *leftSubtree = node->m_left;
    leftSubtree->m_father = node->m_father;
    node->m_father = leftSubtree;
    if(leftSubtree->m_right){
        leftSubtree->m_right->m_father =node;
    }
    node->m_left = node->m_father->m_right;
    node->m_father->m_right = node;
    node->m_height = findNewHeight(node);
    if(node->m_father) {
        node->m_father->m_height = findNewHeight(node->m_father);
    }
    return node->m_father;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::rightRightRotation(Node *node) {
    Node *subTreeRight = node->m_right;
    node->m_right->m_father = node->m_father;
    node->m_father = subTreeRight;
    node->m_right = node->m_father->m_left;
    if(node->m_right)
        node->m_right->m_father = node;
    node->m_father->m_left = node;

    node->m_height = findNewHeight(node);
    if(node->m_father){
        node->m_father->m_height = findNewHeight(node);
    }

    return node->m_father;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::rightLeftRotation(AVLTree<T, Comparison>::Node *node) {
    node->m_right = leftLeftRotation(node->m_right);
    return rightRightRotation(node);
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::leftRightRotation(AVLTree<T, Comparison>::Node *node) {
    node->m_left = rightRightRotation(node->m_left);
    return leftLeftRotation(node);
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node *AVLTree<T, Comparison>::copyNode(AVLTree<T, Comparison>::Node* node) {
    if(node == NULL){
        return NULL;
    }
    Node* left = copyNode(node->m_left);
    Node* right = copyNode(node->m_right);

    Node* new_node = initNode(*node->m_value);
//    new_node->father = node->father;
    new_node->m_left = left;
    if(new_node->m_left)
        new_node->m_left->m_father = new_node;
    new_node->m_right = right;
    if(new_node->m_right)
        new_node->m_right->m_father = new_node;
    new_node->m_height = findNewHeight(new_node);
    return new_node;
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node* AVLTree<T, Comparison>::findMin(AVLTree<T, Comparison>::Node* node) const{
    if (node == NULL) {
        return NULL;
    }
    if (node->m_left == NULL) {
        return node;
    }

    return findMin(node->m_left);
}

template<class T, class Comparison>
typename AVLTree<T, Comparison>::Node* AVLTree<T, Comparison>::findMax(AVLTree<T, Comparison>::Node* node) const{
    if (node == NULL) {
        return NULL;
    }
    if (node->m_right == NULL) {
        return node;
    }

    return findMax(node->m_right);
}

template<class T, class Comparison>
T *AVLTree<T, Comparison>::getMinValueInTree() const {
    return m_minValueNode->m_value;
}

template<class T, class Comparison>
T *AVLTree<T, Comparison>::getMaxValueInTree() const {
    return m_maxValueNode->m_value;
}

#endif //EX1_AVLTREE_H