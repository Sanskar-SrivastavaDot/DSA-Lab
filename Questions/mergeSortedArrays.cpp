#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> result;
    
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n1) {
        result.push_back(arr1[i]);
        i++;
    }

    while (j < n2) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}
