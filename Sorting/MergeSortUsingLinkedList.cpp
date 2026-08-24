#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

Node* merge(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    Node* head = nullptr;
    Node* curr = nullptr;

    if (first->val < second->val) {
        head = first;
        first = first->next;
    } else {
        head = second;
        second = second->next;
    }
    curr = head;

    while (first && second) {
        if (first->val < second->val) {
            curr->next = first;
            first = first->next;
        } else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    if (first) curr->next = first;
    if (second) curr->next = second;

    return head;
}

Node* getMid(Node* head) {
    if (!head || !head->next) return head;
    
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = getMid(head);
    Node* nextToMid = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMid);

    return merge(left, right);
}
