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
void mirrorTree(Node *root) {
    if(!root) return;

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
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


    mirrorTree(root);

}