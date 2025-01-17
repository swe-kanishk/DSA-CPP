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
void sizeofBinaryTree(Node *root, int &size) {
    if(root == NULL) return;
    size += 1;
    sizeofBinaryTree(root->left, size);
    sizeofBinaryTree(root->right, size);
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
    int size = 0;
    sizeofBinaryTree(root, size);
    cout<<size;
}