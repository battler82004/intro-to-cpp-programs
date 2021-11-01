/*
  Title: Exercise 10-6 (Roman Numeral Converter)
  Description: This program takes in a roman numeral, stores it in a
  class object, converts the numeral into an arabic number, and ouputs
  said arabic number.
  Author: James Taddei
  Date: 11/1/21
*/

#include <iostream>
#include <string>
#include <cctype>
#include "roman.h" // Defines and declaraes romanType
using namespace std;

int main() {
  // Variable declarations
  romanType userNum;
  string temp;

  // Program description
  cout << "This program takes in a roman numeral, stores it in a " <<
  "class object, converts the numeral into an arabic number, and " <<
  "ouputs said arabic number." << endl;

  // User input
  cout << "Enter a roman numeral: ";
  cin >> temp;

  userNum.setRomanNumeral(temp); // Sets the value of the roman numeral

  userNum.convertToInt(); // Converts the numeral into a standard int
  userNum.printArabicNum(); // Outputs the standard int (arabic num)

  return 0;
}
