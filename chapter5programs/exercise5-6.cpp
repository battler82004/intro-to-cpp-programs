/*
  Title: Exercise 5-6 (Prime Finder)
  Description: This program takes a positive integer as an input and
  outputs whether or not the number is prime.
  Author: James Taddei
  Date: 9/20/21
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Variable declaration
    int inNum;
    bool isPrime = true;

    // Program description
    cout << "This program takes a positive integer as an input and "
    << "outputs whether the number is prime." << endl;

    // Variable input
    cout << "Enter a positive integer: ";
    cin >> inNum;

    // Checks if the num is prime or not
    if ((inNum != 2) && (inNum % 2) == 0) { // Checks if the number is even
      isPrime = false;
    }
    else { // Checks if the num is divisible by any odd integer
      for (int i = 3; i <= sqrt(inNum); i += 2) {
        if ((inNum % i) == 0) {
          isPrime = false;
          break;
        }
      }
    }

    // Final output
    if (isPrime) {
      cout << endl << "The number (" << inNum << ") is a prime number"
      << endl;
    }
    else {
      cout << endl << "The number (" << inNum << ") is not a prime "
      << "number" << endl;
    }

    return 0;
}
