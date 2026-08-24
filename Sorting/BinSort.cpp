#include <bits/stdc++.h>
using namespace std;

void binSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    auto mn = *min_element(arr.begin(),arr.end());
    auto mx = *max_element(arr.begin(),arr.end());


    long long range = mx - mn;

    if (range == 0) return;

    vector<vector<int>> bins(n);

    for (int i = 0; i < n; i++) {
        int binIndex = ((arr[i]-mn)*(n-1))/range;
        bins[binIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(bins[i].begin(), bins[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int val : bins[i]) {
            arr[index++] = val;
        }
    }
}

void showArr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = {12,32,1,2,3,452,4211,231,21,34452,421};
    showArr(arr);
    binSort(arr);
    cout << "Sorted : ";
    showArr(arr);
    
    return 0;
}
