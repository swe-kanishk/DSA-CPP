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
bool isIdentical(Node *root1, Node *root2) {
    if(!root1 && !root2) return 1;
    if(!root1 || !root2) return 0;

    if(root1->data == root2->data) {
        bool leftResult = isIdentical(root1->left, root2->left);
        bool rightResult = isIdentical(root1->right, root2->right);
        if(leftResult == true && rightResult == true) return true;
    }
    return false; 
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
    cout<<"Enter root elem of root1 : ";
    Node *root1 = BinaryTree();

    cout<<endl;

    cout<<"Enter root elem of root2 : ";
    Node *root2 = BinaryTree();

    cout<<isIdentical(root1, root2);

}