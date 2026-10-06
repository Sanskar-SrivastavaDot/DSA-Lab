#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node*root,int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

Node* buildBTree(vector<int> arr){
    Node* root= NULL;
    for(int x : arr){
        root=insert(root,x);
    }
    return root;
}

void PreorderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    PreorderTraversal( root->left);
    PreorderTraversal( root->right);
}

void InorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    InorderTraversal( root->left);
    cout << root->data << " ";
    InorderTraversal( root->right);
}

void PostorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    PostorderTraversal( root->left);
    PostorderTraversal( root->right);
    cout << root->data << " ";
}

bool Bsearch(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(key==root->data){
        return true;
    }
    if(root->data<key){
        return Bsearch(root->right,key);
    }
    return Bsearch(root->left,key);
}

Node* getIS(Node* root){
    while(root!= NULL && root->left!= NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data > key){
        root->left = delNode(root->left,key);
    }else if(root->data < key){
        root->right = delNode(root->right,key);
    }else{
        if(root->left == NULL && root->right == NULL){ // no child
            delete root;
            return NULL;
        }else if(root->left == NULL || root->right == NULL){  // 1 child
            Node* r = (root->left) ? root->left : root->right;
            delete root;
            return r;
        }else{  // 2 children
            Node* IS = getIS(root->right); // leftMost Node in right Sub Tree
            root->data = IS->data;
            root->right = delNode(root->right,IS->data);
        }
    }
    return root;
}

void printLevelWise(Node* root){
    if(root==NULL){
        cout << endl;
    }
    queue<Node*> tree;
    tree.push(root);
    tree.push(NULL);

    while(tree.size()>0){
        Node* curr = tree.front();
        tree.pop();

        if(curr==NULL){
            if(tree.size()!=0){
                tree.push(NULL);
                cout << endl;
                continue;
            }else{
                break;
            }
        }
        cout << curr->data << " ";

        if(curr->left){
            tree.push(curr->left);
        }
        if(curr->right){
            tree.push(curr->right);
        }
    }
}

int main() {
    vector<int> arr = {20,12,3,1,2,34,21,44,5,6,7};
    Node* root = buildBTree(arr);
    InorderTraversal(root);
    cout << endl;
    printLevelWise(root);

    return 0;
}