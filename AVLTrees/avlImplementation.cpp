#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Node {
    char data;
    Node* left = NULL;
    Node* right = NULL;
    int height = 1;

    Node(char val) : data(val) {}
};

int h(Node* n) {
    return n ? n->height : 0;
}

int getBalanceFactor(Node* n) {
    return n ? h(n->left) - h(n->right) : 0;
}

Node* rotateRight(Node* parent) {
    cout << "Rotate right on node " << parent->data << endl;
    Node* child = parent->left;
    parent->left = child->right;
    child->right = parent;

    parent->height = 1 + max(h(parent->left), h(parent->right));
    child->height = 1 + max(h(child->left), h(child->right));

    return child;
}

Node* rotateLeft(Node* parent) {
    cout << "Rotate left on node " << parent->data << endl;
    Node* child = parent->right;
    parent->right = child->left;
    child->left = parent;

    parent->height = 1 + max(h(parent->left), h(parent->right));
    child->height = 1 + max(h(child->left), h(child->right));

    return child;
}

Node* rotateLeftRight(Node* n) {
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}

Node* rotateRightLeft(Node* n) {
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}

Node* minNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node* balanceTree(Node* root) {
    if (!root) return nullptr;

    root->height = 1 + max(h(root->left), h(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        }
        return rotateLeftRight(root);
    }

    if (balance < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        }
        return rotateRightLeft(root);
    }

    return root;
}

Node* insert(Node* root, char data) {
    if (!root) return new Node(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root;
    }

    return balanceTree(root);
}

Node* remove(Node* root, char target) {
    if (!root) return nullptr;

    if (target < root->data) {
        root->left = remove(root->left, target);
    } else if (target > root->data) {
        root->right = remove(root->right, target);
    } else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }

    return balanceTree(root);
}

void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    Node* root = nullptr;
    vector<char> letters = {'C', 'B', 'E', 'A', 'D', 'H', 'G', 'F'};

    for (char letter : letters) {
        root = insert(root, letter);
    }

    cout << "Initial tree: ";
    printInOrder(root);
    cout << endl << endl;

    cout << "Removing E..." << endl;
    root = remove(root, 'E');
    
    cout << "\nTree after removal: ";
    printInOrder(root);
    cout << endl;

    return 0;
}