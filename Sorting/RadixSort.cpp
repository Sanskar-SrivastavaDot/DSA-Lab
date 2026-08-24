#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

void append(Node*& head, Node*& tail, Node* node) {
    node->next = nullptr;
    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

int get_max(Node* head) {
    int max_val = head->val;
    Node* curr = head->next;
    while (curr) {
        if (curr->val > max_val) {
            max_val = curr->val;
        }
        curr = curr->next;
    }
    return max_val;
}

Node* radix_sort(Node* head) {
    if (!head || !head->next) return head;

    int max_val = get_max(head);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        Node* b_head[10] = { NULL };
        Node* b_tail[10] = { NULL };

        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next;
            int digit = (curr->val / exp) % 10;
            append(b_head[digit], b_tail[digit], curr);
            curr = nxt;
        }

        head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < 10; ++i) {
            if (b_head[i]) {
                if (!head) {
                    head = b_head[i];
                    tail = b_tail[i];
                } else {
                    tail->next = b_head[i];
                    tail = b_tail[i];
                }
            }
        }
    }

    return head;
}

void print_list(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr = {202,1,34,53,643,22,31,34,724};
    
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int v : arr) {
        append(head, tail, new Node(v));
    }

    print_list(head);
    head = radix_sort(head);
    print_list(head);
    return 0;
}
