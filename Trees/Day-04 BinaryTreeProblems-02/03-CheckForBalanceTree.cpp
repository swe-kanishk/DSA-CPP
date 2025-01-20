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
int Height(Node *root, bool &isValid) {
    if(!root) return 0;
    
    int leftHeight = Height(root->left, isValid);
    int rightHeight = Height(root->right, isValid);
    if(abs(leftHeight-rightHeight) > 1) isValid = false;
    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(Node* root) {
    bool isValid = true;
    Height(root, isValid);
    return isValid;
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


    cout<<isBalanced(root);

}