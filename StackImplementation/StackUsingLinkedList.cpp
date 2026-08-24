#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next; 
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private: 
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int val) {
    Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode == nullptr) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int peek() {
        if (topNode == nullptr) return -1;
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};
