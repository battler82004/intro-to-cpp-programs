/*
  Title: Exercise 5-1 (Digits and Sum of Digits)
  Description: This program will take an integer as an input then
  output the individual digits of the integer and the sum of the digits.
  Author: James Taddei
  Date: 9/20/21
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variable declaration
    string inNum, individualDigits;
    int sumOfDigits;

    // Program description
    cout << "Description: This program will take an integer as an " <<
    "input then output the individual digits of the integer and the "
    << "sum of the digits." << endl;

    // Variable input
    cout << "Enter an integer: ";
    cin >> inNum;

    // Removes the negative sign from inNum if there is one
    if ((inNum[0]) == '-') {
        string temp;
        for (int i = 1; i < inNum.length(); i++) {
          temp = temp + inNum[i];
        }
        inNum = temp;
    }

    // Creates the output variables as the first digit in inNum
    individualDigits = inNum[0];
    sumOfDigits = static_cast<int>(inNum[0]) - 48; // Subtract 48 to deal with str to int conversion

    // Adds the non-first digits to the output variables
    for (int i = 1; i < inNum.length(); i++) {
      individualDigits = individualDigits + " " + inNum[i];
      sumOfDigits += static_cast<int>(inNum[i]) - 48;
    }

    // Final outputs
    cout << endl << "The individual digits of " << inNum << " are "
    << individualDigits << endl;
    cout << "The of sum the digits is " << sumOfDigits << endl;

    return 0;
}
