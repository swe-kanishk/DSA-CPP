// Method: 2, for creating a binary tree

#include<iostream>
#include<vector>
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

void PreOrderTraversal(Node *root, vector<int> &ans) { // Pre-order Traversal (NLR)
    if(root == NULL) return;

    ans.push_back(root->data);
    PreOrderTraversal(root->left, ans);
    PreOrderTraversal(root->right, ans);
}
void InOrderTraversal(Node *root, vector<int> &ans2) { // In-order Traversal (LNR)
    if(root == NULL) return;

    InOrderTraversal(root->left, ans2);
    ans2.push_back(root->data);
    InOrderTraversal(root->right, ans2);
}
void PostOrderTraversal(Node *root, vector<int> &ans3) {
    if(root == NULL) return;

    PostOrderTraversal(root->left, ans3);
    PostOrderTraversal(root->right, ans3);
    ans3.push_back(root->data);
}
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

    vector<int> ans;
    PreOrderTraversal(root, ans);

    vector<int> ans2;
    InOrderTraversal(root, ans2);

    vector<int> ans3;
    PostOrderTraversal(root, ans3);


}