/*
  Title: Exercise 6-3 (Num of Vowel Finder)
  Description: This program will take a sequence of characters as an
  input and find the number of vowels in the string.
  Author: James Taddei
  Date: 9/27/21
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Functions prototypes
bool isVowel(char letter);

int main() {
    // Variable declaration
    string seqOfChars;
    int numOfVowels = 0;

    // Program description
    cout << "This program will take a sequence of characters as " <<
    "an input and find the number of vowels in the string." << endl;

    // Variable input
    cout << "Enter a set of characters which you want the number " <<
    "of vowels for: ";
    getline(cin, seqOfChars);

    // Num of vowels finder
    for (int i = 0; i < seqOfChars.length(); i++) { // Goes through each letter and checks if it's a vowel
        if (isVowel(static_cast<char>(tolower(static_cast<char>(seqOfChars[i]))))) {
            numOfVowels++; // Adds 1 to num of vowels if the curr letter is a vowel
        }
    }

    // Final output
    cout << endl << "There are " << numOfVowels << " vowels in " <<
    "this sentence." << endl;

    return 0;
}

// This function checks if the inputted letter is a vowel
bool isVowel(char letter) { // Finds if the parameter is a vowel or not
    if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u') {
      return true;
    }

    return false;
}
