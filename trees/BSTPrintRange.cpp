/*
Print range in a binary search tree
*/

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    private:
    BinaryTreeNode * leftChild = 0;
    BinaryTreeNode * rightChild = 0;
    T nodeValue;
    
    public:
    void insert(T);
    void printRange(BinaryTreeNode *, T, T);
    ~BinaryTreeNode();
    BinaryTreeNode(T);
};

template <typename T>
BinaryTreeNode <T>::BinaryTreeNode(T value){
    this->nodeValue = value;  //can also use (*this).nodeValue = value;
    this->rightChild = 0;
    this->leftChild = 0;
}

template <typename T>
void BinaryTreeNode <T>::insert(T value){
    if(value < this->nodeValue){
        if (this->leftChild == 0){
            //insert here
            this->leftChild = new BinaryTreeNode <T>(value);
        } else {
            this->leftChild->insert(value);
        }
    } else {
        if (this->rightChild == 0){
            //insert here
            this->rightChild = new BinaryTreeNode <T>(value);
        } else {
            this->rightChild->insert(value);
        }
    }
}

template <typename T>
void BinaryTreeNode <T>::printRange(BinaryTreeNode * node, T startValue, T endvalue){
    if (node == 0){
        return;
    }
    //smaller values are on the left, so only go left if they can still be in range
    if (node->nodeValue > startValue){
        printRange(node->leftChild, startValue, endvalue);
    }
    if (node->nodeValue >= startValue && node->nodeValue <= endvalue){
        cout<<node->nodeValue<<" ";
    }
    //equal values are inserted on the right, so go right while still within range
    if (node->nodeValue <= endvalue){
        printRange(node->rightChild, startValue, endvalue);
    }
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode(){
    delete this->rightChild;
    delete this->leftChild;
}

int main(){
    BinaryTreeNode <int> bst(8);
    bst.insert(1);
    bst.insert(16);
    bst.insert(7);
    bst.insert(3);
    bst.printRange(&bst,1,5);
    cout<<endl;
    return 0;
}