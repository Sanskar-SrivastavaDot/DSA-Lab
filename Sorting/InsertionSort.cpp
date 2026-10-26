#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSortBinary(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int low = 0, high = i - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        for (int j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
        }
        arr[low] = key;
    }
}

int main() {
    vector<int> data = {50, 20, 60, 10, 30, 40, 5};
    
    insertionSortBinary(data);
    
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
