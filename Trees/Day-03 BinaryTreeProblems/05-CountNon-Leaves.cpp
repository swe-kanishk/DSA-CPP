#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
int totalNonLeaves(Node *root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 0;

    return 1 + totalNonLeaves(root->left) + totalNonLeaves(root->right);
}
Node *BinaryTree() {
    int x;
    cin>>x;
    if(x == -1) return NULL;

    Node *temp = new Node(x);
    cout<<"Enter left elem of "<<x<<" : ";
    temp->left = BinaryTree();
    cout<<"Enter right elem of "<<x<<" : ";
    temp->right = BinaryTree();

    return temp;
}
int main(){
    cout<<"Enter root elem : ";

    Node *root = BinaryTree();

    cout<<"Total non leaves on this tree is : "<<totalNonLeaves(root);
}