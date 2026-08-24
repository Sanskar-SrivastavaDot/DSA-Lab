#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char src, char dst, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dst << "\n";
        return;
    }
    
    hanoi(n - 1, src, aux, dst);
    cout << "Move disk " << n << " from " << src << " to " << dst << "\n";
    hanoi(n - 1, aux, dst, src);
}

int main() {
    int disks = 3;
    hanoi(disks, 'A', 'C', 'B');
    return 0;
}
