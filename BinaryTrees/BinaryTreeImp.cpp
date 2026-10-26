#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int val, Node* parent) {
        this->val = val;
        this->left = this->right = nullptr;
        this->parent = parent;
    }
};

Node* createTree(int val, Node* parent) {
    Node* root = new Node(val, parent);
    int left, right;
    cout << "Left child? Right Child?(Give -1 if a child is NULL) for Node " << root->val << " ";
    cin >> left >> right;
    
    if (left == -1 && right == -1) {
        return root;
    }
    if (left != -1) {
        root->left = createTree(left, root);
    }
    if (right != -1) {
        root->right = createTree(right, root);
    }
    return root;
}

bool searchNode(Node* root, int target) {
    if (root == nullptr) return false;
    if (root->val == target) return true;
    
    return searchNode(root->left, target) || searchNode(root->right, target);
}

Node* findTargetNode(Node* root, int target) {
    if (root == nullptr) return nullptr;
    if (root->val == target) return root;
    
    Node* leftSearch = findTargetNode(root->left, target);
    if (leftSearch != nullptr) return leftSearch;
    
    return findTargetNode(root->right, target);
}

void insertIntoTree(Node* root) {
    if (root == nullptr) return;
    
    int targetParent, childVal;
    char choice;
    cout << "Enter target parent node value to insert under: ";
    cin >> targetParent;
    
    Node* targetNode = findTargetNode(root, targetParent);
    if (targetNode == nullptr) {
        cout << "Parent node not found." << endl;
        return;
    }
    
    cout << "Insert as left child (l) or right child (r)? ";
    cin >> choice;
    cout << "Enter new node value: ";
    cin >> childVal;
    
    if (choice == 'l' || choice == 'L') {
        if (targetNode->left != nullptr) {
            cout << "Left child already occupied." << endl;
        } else {
            targetNode->left = new Node(childVal, targetNode);
            cout << "Node inserted." << endl;
        }
    } else if (choice == 'r' || choice == 'R') {
        if (targetNode->right != nullptr) {
            cout << "Right child already occupied." << endl;
        } else {
            targetNode->right = new Node(childVal, targetNode);
            cout << "Node inserted." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteFromTree(Node* root, int target) {
    if (root == nullptr) return nullptr;
    
    Node* targetNode = findTargetNode(root, target);
    if (targetNode == nullptr) {
        cout << "Node to delete not found." << endl;
        return root;
    }
    
    Node* parentNode = targetNode->parent;
    
    if (targetNode->left == nullptr && targetNode->right == nullptr) {
        if (parentNode != nullptr) {
            if (parentNode->left == targetNode) parentNode->left = nullptr;
            else parentNode->right = nullptr;
            delete targetNode;
        } else {
            delete targetNode;
            root = nullptr;
        }
    }
    else if (targetNode->left == nullptr || targetNode->right == nullptr) {
        Node* child = (targetNode->left != nullptr) ? targetNode->left : targetNode->right;
        child->parent = parentNode;
        
        if (parentNode != nullptr) {
            if (parentNode->left == targetNode) parentNode->left = child;
            else parentNode->right = child;
            delete targetNode;
        } else {
            delete targetNode;
            root = child;
        }
    }
    else {
        Node* successor = findMin(targetNode->right);
        int successorVal = successor->val;
        root = deleteFromTree(root, successorVal);
        
        targetNode = findTargetNode(root, target);
        if (targetNode != nullptr) {
            targetNode->val = successorVal;
        }
    }
    return root;
}

void preOrderSequence(Node* root) {
    if (root == nullptr) {
        cout << -1 << " ";
        return;
    }
    cout << root->val << " ";
    preOrderSequence(root->left);
    preOrderSequence(root->right);
}

void inOrderSequence(Node* root) {
    if (root == nullptr) return;
    inOrderSequence(root->left);
    cout << root->val << " ";
    inOrderSequence(root->right);
}

void postOrderSequence(Node* root) {
    if (root == nullptr) return;
    postOrderSequence(root->left);
    postOrderSequence(root->right);
    cout << root->val << " ";
}

int main() {
    cout << "Build your binary tree dynamically:" << endl;
    Node* root = createTree(9, nullptr);
    
    cout << "\nInitial Pre-Order Sequence: ";
    preOrderSequence(root);
    cout << endl;
    
    cout << "\n--- Inserting a new node ---" << endl;
    insertIntoTree(root);
    
    cout << "Pre-Order after insertion: ";
    preOrderSequence(root);
    cout << endl;
    
    int valToDelete;
    cout << "\n--- Deleting a node ---" << endl;
    cout << "Enter node value to delete: ";
    cin >> valToDelete;
    root = deleteFromTree(root, valToDelete);
    
    cout << "Pre-Order after deletion: ";
    preOrderSequence(root);
    cout << endl;
    
    return 0;
}
