#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSortBidirectional(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start < end) {
        int minIdx = start;
        int maxIdx = start;
        
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }
        
        swap(arr[start], arr[minIdx]);
        
        if (maxIdx == start) {
            maxIdx = minIdx;
        }
        
        swap(arr[end], arr[maxIdx]);
        
        start++;
        end--;
    }
}

int main() {
    vector<int> data = {29, 10, 14, 37, 13, 5, 8};
    
    selectionSortBidirectional(data);
    
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
