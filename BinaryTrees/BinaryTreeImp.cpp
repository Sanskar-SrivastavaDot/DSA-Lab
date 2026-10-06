#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;
        Node(int val,Node* parent){
            this->val = val;
            this->left = this->right = NULL;
            this->parent = parent;
        }
};

Node* createTree(int val,Node* parent){
    Node* root = new Node(val,parent);
    int left,right;
    cout << "Left child? Right Child?(Give -1 if a child is NULL) for Node " << root->val << " ";
    cin >> left >> right;
    if(left==-1 && right == -1){
        return root;
    }
    if(left!=-1){
        root->left = createTree(left,root);
    }
    if(right!=-1){
        root->right = createTree(right,root);
    }
    return root;
}
bool searchNode(Node* root, int target){
    if(root==NULL) return false;
    if(root!=NULL && root->val == target){
        return true;
    }
    bool left = searchNode(root->left,target);
    bool right = searchNode(root->right,target);

    return left || right;
}
void insertIntoTree(Node* root){
    
}
void preOrderSequence(Node* root){
    if(root==NULL){
        cout << -1 << " ";
        return;
    }
    cout << root->val << " ";
    preOrderSequence(root->left);
    preOrderSequence(root->right);
}
int main() {
    Node* root = createTree(9,NULL);
    preOrderSequence(root);
    
    return 0;
}