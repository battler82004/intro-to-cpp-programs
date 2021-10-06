// Falling Distance Calculator
// James Taddei
// 10/6/21

#include <iostream>
#include <iomanip>
using namespace std;

double fallingDistance(int time);

const double GRAVITY = 9.8;

int main() {
    cout << showpoint << setprecision(2) << fixed;
    cout << "Time\tDistance" << endl;
    // Loop purpose is just to show the results of a variety of values from 1 to 10
    for(int i = 1; i <= 10; i++) {
        cout << i << "\t\t" << fallingDistance(i) << endl;
    }

    return 0;
}

double fallingDistance(int time) {
    return 0.5 * GRAVITY * time * time; // Formula: d = 0.5*g*t^2
}