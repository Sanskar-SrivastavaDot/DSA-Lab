#include <bits/stdc++.h>
using namespace std;
void merge(int l,int mid,int r,vector<int>&arr){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergeSort(vector<int>&arr,int l,int r){
    if(l>=r){
        return;
    }
    int mid = (l+r) >> 1;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);

    merge(l,mid,r,arr);
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
    mergeSort(arr,0,arr.size()-1);
    cout << "Sorted : ";
    showArr(arr);
    
    return 0;
}