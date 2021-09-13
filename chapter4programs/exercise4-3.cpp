/*
  Title: Exercise 4-3 (Integer Converter)
  Description: This program takes an integer as an input and outputs
  the number if it's less than 10 or the corresponding letter if the
  integer is >= 10.
  Author: James Taddei
  Date: 9/13/21
*/

#include <iostream>
using namespace std;

int main() {
    // Variable declaration
    int num;

    // Program description
    cout << "This program takes an integer as an input and outputs " <<
    "the number if it's less than 10 or the corresponding letter if " <<
    "the integer is >= 10." << endl;

    // Variable input
    cout << "Enter an integer between 0 and 35:";
    cin >> num;

    // Checks if num is less than or equal to nine or greater than it
    if (num <= 9) { // Outputs the num if it's <= 9
      cout << endl << "The number was: " << num << endl;
    }
    else { // Outputs the corresponding letter if num >= 10
      num += 55;
      cout << endl << "The corresponding character is: " << 
      static_cast<char>(num) << endl;
    }

    return 0;
}
