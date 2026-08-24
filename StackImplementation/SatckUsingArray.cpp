#include <bits/stdc++.h>
using namespace std;

class Stack {
    int* arr;
    int cap;
    int topIndex;

public:
    Stack(int size) {
        cap = size;
        arr = new int[cap];
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex == cap - 1) return;
        topIndex++;
        arr[topIndex] = val;
    }

    void pop() {
        if (topIndex == -1) return;
        topIndex--;
    }

    int top() {
        if (topIndex == -1) return -1;
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};


int main(){
    int cap;
    cout << "Enter the capacity of the Stack: ";
    cin >> cap;
    Stack st(cap);

    st.push(10);
    st.push(19);
    st.push(18);
    
}