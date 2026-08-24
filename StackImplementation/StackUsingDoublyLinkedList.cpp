#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int v) {
        Node* n = new Node(v);
        if (top != nullptr) {
            top->next = n;
            n->prev = top;
        }
        top = n;
    }

    void pop() {
        if (top == nullptr) return;
        Node* tmp = top;
        top = top->prev;
        if (top != nullptr) {
            top->next = nullptr;
        }
        delete tmp;
    }

    int peek() {
        if (top == nullptr) return -1;
        return top->val;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
