#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cout << "Enter the coeficients of x^2 and x then constant term:";
    cin >> a >> b >> c;

    int d = b*b-4*a*c;
    if(d==0){
        cout << "Equation has single root: " << (-b)/(2*a);
    }
    else if(d>0){
        cout << "Roots of the equations are: " << (-b + sqrt(d))/(2*a) << " " << (-b - sqrt(d))/(2*a);
    }
    else{
        cout << "No real roots exists." << endl;
    }
    return 0;
}