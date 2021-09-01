/*
    Title: Number of Cans Needed Calc
    Description: This program finds the number of paint cans needed to cover a 6 ft high
        100 ft long fence in 2 coats if the paint covers 340 sq ft per gallon.
    Author: James Taddei
    Date: 9/1/21
*/

#include <iostream>
using namespace std;

const int SQ_FT_PER_GALLON = 340;

int main() {
    // Variable declaration + assignment
    int length = 100, height = 6, sqFootage, cansOfPaint;
    
    // Calculations
    sqFootage = height * length * 2; // Finds the sq footage that needs to be covered (including the second coat)
    cansOfPaint = sqFootage / SQ_FT_PER_GALLON + 1; // Finds the number of cans of paint needed (rounded up)
    
    // Final outputs
    cout << "You'll need " << cansOfPaint << " cans (gallons) of paint for the fence." << endl;

    return 0;
}