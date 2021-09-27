/*
  Title: Exercise 6-2 (Vowel Checker)
  Description: This program will print out whether or not an entered
  letter is a vowel.
  Author: James Taddei
  Date: 9/27/21
*/

#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes
bool isVowel(char letter);

int main() {
    // Variable declaration
    char inLetter;

    // Program description
    cout << "This program will print out whether or not an entered " <<
    "letter is a vowel." << endl;

    // Variable input
    cout << "Enter a letter: ";
    cin >> inLetter;

    // Final output
    cout << endl << inLetter << " is a vowel: " <<
    isVowel(tolower(inLetter)) << endl;

    return 0;
}

bool isVowel(char letter) { // Finds if the parameter is a vowel or not
    if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u') {
      return true;
    }

    return false;
}
