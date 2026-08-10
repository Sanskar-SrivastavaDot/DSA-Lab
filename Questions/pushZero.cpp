#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {1,0,2,3,4,0,8,0,7,0};
    vector<int> ans(vec.size(),0);
    int i = 0;
    for(int x : vec){
        if(x!=0){
            ans[i] = x;
            i++;
        }
    }
    for(int s : ans) cout << s << " ";
    
    return 0;
}