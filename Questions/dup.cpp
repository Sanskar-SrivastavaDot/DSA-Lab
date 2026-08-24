#include <bits/stdc++.h>
using namespace std;

int findFirstDuplicate(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr = {2, 5, 1, 2, 3, 5, 1, 2, 4};
    
    int result = findFirstDuplicate(arr);
    
    if (result != -1) {
        cout << "First duplicate element is: " << result << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}
