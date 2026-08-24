#include <iostream>
using namespace std;

class CircularQueue {
public:
    const int cap = 100;
    int st = -1;
    int end = -1;
    int* queue;

    CircularQueue() {
        queue = new int[cap];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return st == -1;
    }

    bool isFull() {
        return (end + 1) % cap == st;
    }

    void add(int val) {
        if (isFull()) {
            cout << "Capacity of the Queue is Full." << endl;
            return;
        }

        if (isEmpty()) {
            st = 0;
        }

        end = (end + 1) % cap;
        queue[end] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is already Empty." << endl;
            return;
        }

        cout << "Removed: " << queue[st] << endl;

        if (st == end) {
            st = -1;
            end = -1;
        } else {
            st = (st + 1) % cap;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return -1;
        }

        return queue[st];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }

        cout << "Queue: ";

        int i = st;

        while (true) {
            cout << queue[i] << " ";

            if (i == end)
                break;

            i = (i + 1) % cap;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);

    q.display();

    cout << "Front: " << q.front() << endl;

    q.pop();
    q.pop();

    q.display();

    q.add(50);
    q.add(60);

    q.display();

    cout << "Front: " << q.front() << endl;

    return 0;
}