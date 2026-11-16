
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNode(Node* head, int index) {
    for (int i = 0; i < index; i++) {
        head = head->next;
    }
    return head;
}
void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void heapify(Node* head, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        getNode(head, left)->data >
        getNode(head, largest)->data) {
        largest = left;
    }

    if (right < n &&
        getNode(head, right)->data >
        getNode(head, largest)->data) {
        largest = right;
    }

    if (largest != i) {
        swapData(getNode(head, i),
                 getNode(head, largest));

        heapify(head, n, largest);
    }
}

// Heap Sort
void heapSort(Node* head) {
    int n = countNodes(head);

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(head, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swapData(head, getNode(head, i));
        heapify(head, i, 0);
    }
}

// Display linked list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insert(head, 40);
    insert(head, 10);
    insert(head, 30);
    insert(head, 50);
    insert(head, 20);

    cout << "Original List: ";
    display(head);

    heapSort(head);

    cout << "Sorted List: ";
    display(head);

    return 0;
}
