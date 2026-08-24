#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double u, angle;
    double g = 9.81;
    double PI = 3.14159;

    cout << "Enter velocity (m/s): ";
    cin >> u;
    cout << "Enter angle (degrees): ";
    cin >> angle;

    double rad = angle * PI / 180.0;

    double height = (u * u * sin(rad) * sin(rad)) / (2 * g);

    cout << "Maximum Height: " << height << " meters" << endl;
    return 0;