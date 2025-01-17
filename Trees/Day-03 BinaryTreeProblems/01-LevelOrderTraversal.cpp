#include<iostream>
#include<queue>
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
vector<int> LevelOrderTraversal(Node *root) {
    queue<Node *> q;
    q.push(root);

    vector<int> ans;

    Node *temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        
        ans.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    return ans;
}
Node *BinaryTree() {
    int x;
    cin>>x;

    if(x == -1) return NULL;

    Node *temp = new Node(x);

    // left 
    cout<<"Enter left child of "<<x<<" : ";
    temp->left = BinaryTree();
    // right 
    cout<<"Enter right child of "<<x<<" : ";
    temp->right = BinaryTree();

    return temp;
}
int main(){
    cout<<"Enter root node: ";

    Node *root = BinaryTree();
    vector<int>LevelOrderTraverse = LevelOrderTraversal(root);

    int size = LevelOrderTraverse.size();
    for(int i = 0; i<size; i++){
        cout<<LevelOrderTraverse[i]<<", ";
    }
}