/*
    Title: Pointers Ex
    Author: James Taddei
    Date: 11/22/21
*/

#include <iostream>
using namespace std;

int main() {
    double radius = 7;
    double *radiusPtr = &radius;
    // sets radiusPtr to hold the location of radius
    
    cout << "Enter radius: ";
    cin >> *radiusPtr;
    // this will change the value of radius since they have the same
    // address
    cout << endl;
    
    cout << "r = " << radius << endl;
    cout << "r location = " << &radius << endl;
    cout << "rPtr = " << radiusPtr << endl;
    cout << "r from Ptr = " << *radiusPtr << endl;
    // gets the value at location radiusPtr by adding an asterisk to
    // the front

    return 0;
}