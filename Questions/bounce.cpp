#include <iostream>
using namespace std;

int main() {
    int s;
    cout << "Enter the speed of the ball(m/s): " ;
    cin >> s;
    int c = 0;
    while(s>0){
        c++;
        s=s/2;
    }
    cout << "The number of bounces the ball will have: "<< c << endl;
    
    return 0;
}