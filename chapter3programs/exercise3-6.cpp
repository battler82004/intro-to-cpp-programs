/*
  Title: Exercise 3-6 (Volume Calculator)
  Description: This program will find the volume in cubic centimeters after the
  mass (in grams) and density (in grams per cubic centimeters) is inputted.
  Author: James Taddei
  Date: 9/7/21
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Variable declaration
    double mass, density, volume;

    // Program description
    cout << "This program will find the volume in cubic centimeters " <<
    "after the mass (in grams) and density (in grams per cubic " <<
    " centimeters) is inputted." << endl;

    // Variable input
    cout << "Object's mass (in grams): ";
    cin >> mass;

    cout << endl << "Object's density (in grams/cm^3): ";
    cin >> density;

    // Calculation
    volume = mass / density;

    // Final outputs
    cout << endl << fixed << setprecision(2);
    cout << "The object's volume is " << volume << " grams per cubic centimeter" << endl;

    return 0;
}
