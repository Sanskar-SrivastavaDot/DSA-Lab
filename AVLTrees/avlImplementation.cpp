#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(TreeNode* node) {
    if (!node) return 0;
    return node->height;
}

int getBalance(TreeNode* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* rightRotate(TreeNode* y) {
    std::cout << "Rotate right on node " << y->data << std::endl;
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    
    x->right = y;
    y->left = T2;
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    std::cout << "Rotate left on node " << x->data << std::endl;
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    
    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}

TreeNode* insert(TreeNode* node, char data) {
    
    if (!node) return new TreeNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    
    inOrderTraversal(node->left);
    std::cout << node->data << ", ";
    inOrderTraversal(node->right);
}

int main() {
    TreeNode* root = nullptr;
    std::vector<char> letters = {'C', 'B', 'E', 'A', 'D', 'H', 'G', 'F'};

    for (char letter : letters) {
        root = insert(root, letter);
    }

    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
