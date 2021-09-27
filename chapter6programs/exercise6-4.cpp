/*
  Title: Exercise 6-4 (Working with Pi)
  Description: This program will find the square root of pi, take in
  the radius of a circle, find the surface are of that circle, and
  find the volume of that circle.
  Author: James Taddei
  Date: 9/27/21
*/

#include <iostream>
#include <cmath> 
#include <iomanip>
using namespace std;

const double PI = 3.14159; // Pi variable creation

// Function prototypes
void sqrtOfPi();
double rInput();
void surfaceAreaCalc(double r);
void volumeCalc(double r);

int main() {
    // Variable declaration
    double r;

    // Program description
    cout << "This program will find the square root of pi, take " <<
    "in the radius of a circle, find the surface are of that " <<
    "circle, and find the volume of that circle." << endl;

    // Output manipulation
    cout << fixed << setprecision(2) << showpoint;

    sqrtOfPi(); // Outputs the sqrt of pi

    r = rInput(); // Variable input for 'r'

    surfaceAreaCalc(r); // Calculates and outputs the surface area

    volumeCalc(r); // Calculates and outputs the volume

    return 0;
}

// Outputs the square root of pi
void sqrtOfPi() {
    cout << "The square root of pi = " << sqrt(PI) << endl;
    return;
}

// Variable (r) input
double rInput() {
    double r;
    cout << "Enter the radius: ";
    cin >> r;
    return r;
}

// Surface area calculator and output
void surfaceAreaCalc(double r) {
    double surfaceArea;
    surfaceArea = 4.0 * PI * pow(r, 2.0);
    cout << endl <<"Surface area of the sphere: 4 * PI * " <<
    r << " ^ 2 = " << surfaceArea << endl;
    return;
}

// Volume calculator and output
void volumeCalc(double r) {
    double volume;
    volume = (4.0 / 3.0) * PI * pow(r, 3.0);
    cout << "Volume of the sphere: 4 / 3 * PI * " << r << 
    " ^ 3 = " << volume << endl;
    return;
}
