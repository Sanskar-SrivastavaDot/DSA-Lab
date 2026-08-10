#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define f(i,x,n) for(int i=x;i<n;i++)
#define endl '\n'

void solve() {
    vector<int> vec = {1,2,3,2,1,2,3};
    unordered_set<int> st;

    for(int x : vec){
        if(st.find(x)!=st.end()){
            cout << x << endl;
            return;
        }
        st.insert(x);
    }

}

signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Uncomment this line for multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}