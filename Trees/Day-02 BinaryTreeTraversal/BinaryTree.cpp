// Method: 2, for creating a binary tree

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};
Node* BinaryTree() {
    int x;
    cin>>x;

    if(x == -1) return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" : ";
    temp->left = BinaryTree();
    cout<<"Enter the right child of "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
}
int main(){
    cout<<"Enter root node: ";
    Node *root;
    root = BinaryTree();
}