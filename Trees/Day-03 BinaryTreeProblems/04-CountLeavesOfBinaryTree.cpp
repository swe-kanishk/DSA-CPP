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
int totalLeaves(Node *root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    return totalLeaves(root->left) + totalLeaves(root->right);
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

    cout<<"Total leaves on this tree is : "<<totalLeaves(root);
}