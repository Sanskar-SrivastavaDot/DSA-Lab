#include <iostream>
#include <vector>
using namespace std;

class LinearQueue {
private:
    vector<int> arr;
    int capacity;
    int frontIndex;
    int rearIndex;

public:
    LinearQueue(int size) {
        capacity = size;
        arr.resize(size);
        frontIndex = 0;
        rearIndex = -1;
    }

    bool enqueue(int val) {
        if (rearIndex >= capacity - 1) {
            cout << "Queue Overflow: Cannot enqueue " << val << "\n";
            return false;
        }
        rearIndex++;
        arr[rearIndex] = val;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Nothing to dequeue\n";
            return false;
        }
        frontIndex++;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1; 
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return frontIndex > rearIndex;
    }
};

int main() {
    LinearQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << "\n"; // Outputs 10

    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << "\n"; // Outputs 20

    return 0;
}
