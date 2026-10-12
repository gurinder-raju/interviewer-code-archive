/*
Serialize a binary tree to a string, and deserialize that string back into the
same tree.
*/

using namespace std;
#include <iostream>


class BinarySearchTree {
    public:
        BinarySearchTree * leftNode;
        BinarySearchTree * rightNode;
        int value;
    
        BinarySearchTree(int val){
            value = val;
            leftNode = NULL;
            rightNode = NULL;
        }
        
        void insert(int val){
            if (val < value){
                if(leftNode != NULL){
                    leftNode->insert(val);
                } else {
                    leftNode = new BinarySearchTree(val);
                }
            } else {
                if (rightNode != NULL){
                    rightNode->insert(val);
                } else {
                    rightNode = new BinarySearchTree(val);
                }
            }
        }
};


string serializeBST(BinarySearchTree * root){
    string rString;
    if(root == NULL){
        rString += "#,";
    } else {
        rString += to_string(root->value) + ",";
        rString += serializeBST(root->leftNode);
        rString += serializeBST(root->rightNode);
    }
    return rString;
}

BinarySearchTree * deserializeBST2(string s, int & sIndex){
     if(sIndex > s.length()-1) return NULL;
     
     string s1;
     while (s[sIndex] != ','){
         s1 += s[sIndex];
         sIndex++;
     }
     sIndex++;

     if (s1 == "#"){
         return NULL;
     } else {
         BinarySearchTree * node = new BinarySearchTree(stoi(s1));
         node->leftNode = deserializeBST2(s,sIndex);
         node->rightNode = deserializeBST2(s,sIndex);
         return node;
     }
}

BinarySearchTree * deserializeBST(string s){
    int sIndex=0;
    return deserializeBST2(s,sIndex);
}

int main(){
    BinarySearchTree * tree = new BinarySearchTree(6);
    tree->insert(8);
    tree->insert(9);
    tree->insert(7);
    tree->insert(4);
    tree->insert(5);
    tree->insert(3);
    tree->insert(1);
    string sBST = serializeBST(tree);
    BinarySearchTree * tree2 = deserializeBST(sBST);
    string sBST2 = serializeBST(tree2);
    cout<<"Serialized Fist Time: "<<sBST<<endl;
    cout<<"Serialized Second Time: "<<sBST2<<endl;
    return 0;
}


