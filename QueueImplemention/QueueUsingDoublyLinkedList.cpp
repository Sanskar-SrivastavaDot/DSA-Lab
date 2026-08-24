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

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int v) {
        Node* n = new Node(v);
        if (tail == nullptr) {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void dequeue() {
        if (head == nullptr) return;
        Node* tmp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete tmp;
    }

    int getFront() {
        if (head == nullptr) return -1;
        return head->val;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};
