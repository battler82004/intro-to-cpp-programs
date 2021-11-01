#include <iostream>
#include "roman.h"
using namespace std;

// This function finds the value of a roman char
int romanType::charValue(char romanChar) {
  romanChar = static_cast<char>(tolower(romanChar));

  if (romanChar == 'm')
    return 1000;
  if (romanChar == 'd')
    return 500;
  if (romanChar == 'c')
    return 100;
  if (romanChar == 'l')
    return 50;
  if (romanChar == 'x')
    return 10;
  if (romanChar == 'v')
    return 5;

  return 1; // romanChar == i
}

void romanType::convertToInt() {
  // Goes through each character and converts them individually to ints
  for (unsigned int i = 0; i < romanNumeral.length(); i++) {
    if (i != 0) { // for all but the first char
      if (charValue(romanNumeral[i]) >= charValue(romanNumeral[i + 1])) {
        // checks that there isn't a lower value char before
        addToArabicNum(charValue(romanNumeral[i]));
      }
      else { // deals with lower value chars before
        addToArabicNum(charValue(romanNumeral[i + 1]) -
        charValue(charValue(romanNumeral[i])));
        i++;
      }
    }
    else if (charValue(romanNumeral[i]) >=
      charValue(romanNumeral[i + 1])) {
      // deals with first char which isn't lower than the next

      addToArabicNum(charValue(romanNumeral[i]));
    }
    else { // deals with first char which is lower than the next
      addToArabicNum(charValue(romanNumeral[i + 1]) -
      charValue(romanNumeral[i]));
      i++;
    }
  }

  return;
}

void romanType::printArabicNum() {
  cout << "The value of the roman numeral is: " << arabicNum << endl;
  return;
}

void romanType::addToArabicNum(int addedNum) {
  arabicNum += addedNum;
  return;
}

void romanType::setRomanNumeral(string numeral) {
  romanNumeral = numeral;
}
