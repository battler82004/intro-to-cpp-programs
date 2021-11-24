/*
  Title: Honors Project - Hangman
  Description: This program allows you to play a text-based version of hangman. To win, the user must find the word in 5 guesses.
  Author: James Taddei
  Credit: Source of words.txt - Xethron (https://github.com/Xethron/Hangman/blob/master/words.txt)
  Date: 11/23/21
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int NUM_OF_WORDS_IN_FILE = 870;

string randomWordPicker(int minimumWordLen);
// Returns a random word whose length is greater than or equal to the minimum word length

int possibleVaues(ifstream &wordsFile, int minimumLen, int possibleWords[]);
// Creates a list of all of the indexes of words that reach the minimum word length. It also returns the index of the last element in the array

void infoPrinter(string wordToGuess, int wordLen, bool letterFound[], int numOfGuesses, char lettersGuesed[], int numOfTotalGuesses);
// Prints some relevant info to the user including the word (with unfound letters covered with underscores), the picture of the hanging man, and all of the previously guessed letters

bool wordFoundChecker(const bool letterFound[], int wordLen);
// Returns whether or not the word has been found as a boolean

char inputLetter();
// Prompts the user to a letter and returns the lowercase letter if it was valid

int inputMinWordLen();
// Promtps the user to enter the minimum word length, checks that the input was valid, and returns it

int main() {
  // Variable declaration
  int minimumWordLen = 0, wordLen = 0, numOfWrongGuesses = 0, numOfTotalGuesses = 0;
  string wordToGuess = "";
  bool wordFound = false;
  bool *letterFound; // Pointer for the dynamic array of indexes of letters which have been found
  char guessedLetter = 'a', playAgain = 'b';
  char lettersGuessed[26]; // Array of letters which have been guessed

  srand(time(0)); // Sets the random seed

  // Program description
  cout << "This program allows you to play a text-based version of hangman. To win, the user must find the word in 5 guesses." << endl << endl;

  // Prompts the user to enter the minimum word length
  cout << "Minimum number of letters (up to 14, type 0 if you don't want a minimum): ";
  minimumWordLen = inputMinWordLen();

  // "Randomly" picks the word to be guessed and finds its length
  wordToGuess = randomWordPicker(minimumWordLen);
  wordLen = wordToGuess.length();

  // Creates a dynamic array which holds a bool storing if the letter had been found
  letterFound = new bool[wordLen];
  for (int i = 0; i < wordLen; i++)
    letterFound[i] = false;

  cout << endl << "The word is " << wordLen << " letters long" << endl; // Outputs the word length

  // Loops allowing the user to guess letters until the word was found or they reached 5 wrong guesses
  do {
    // Outputs info relevant to the user
    infoPrinter(wordToGuess, wordLen, letterFound, numOfWrongGuesses, lettersGuessed, numOfTotalGuesses);

    // Prompts the user to guess a letter
    cout << "Guess a letter: ";
    guessedLetter = inputLetter();

    if (wordToGuess.find(guessedLetter) < wordLen) {
      // If the guessed letter is in the word, the index of those letters in letterFound is set to true
      for (int i = 0; i < wordLen; i++) {
        if (wordToGuess[i] == guessedLetter)
          letterFound[i] = true;
      }
      wordFound = wordFoundChecker(letterFound, wordLen); // Checks if the word was found
    }
    else { // The user's guess was wrong
      numOfWrongGuesses++;
    }
    lettersGuessed[numOfTotalGuesses] = guessedLetter;
    numOfTotalGuesses++; // Adds the letter to the lettersGuessed array
  } while (!wordFound && numOfWrongGuesses < 5);

  // At this point, the user has either won or lost. The result will be displayed and the user will be prompted on if they guessed it or not
  if (!wordFound) {
    // Ouputs the revelant info
    infoPrinter(wordToGuess, wordLen, letterFound, numOfWrongGuesses, lettersGuessed, numOfTotalGuesses);

    // Prints that the user failed to find the word and outputs the word
    cout << "You have failed to find the word with less than 5 wrong guesses. The word was '" << wordToGuess << "'. Better luck next time!" << endl;

    delete [] letterFound; // Deletes the array of the letters found

    // Prompts the user for if they want to play again
    cout << "Would you like to play again (y/Y or n/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
      cout << endl << endl << endl;
      main();
    }
  }
  else { // Runs if the user found the word
    cout << endl << "Good job! You found the word with only " << numOfWrongGuesses << " wrong guess(es)." << endl; // Outputs the number of wrong guesses the user had

    delete [] letterFound; // Deletes the array of the letters found

    // Prompts the user for if they want to play again
    cout << endl << "Would you like to play again (y/Y or n/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
      cout << endl << endl << endl;
      main();
    }
  }
  
  return 0;
}

// Returns a random word whose length is greater than or equal to the minimum word length
string randomWordPicker(int minimumLen) {
  // Variable declaration
  ifstream wordsFile("words.txt");
  string word;
  int possibleWords[NUM_OF_WORDS_IN_FILE] = {0}; // List of indexes of words which are long enough
  int maxIndex = possibleVaues(wordsFile, minimumLen, possibleWords) - 1; // Stores index of the final element in the array possibleWords

  int randPos = (rand() % (maxIndex + 1)), pos = 0; // "Randomly" selects the index of the word to be guessed

  // Returns the word at the randomly selected index
  while (getline(wordsFile, word)) {
    if (pos == possibleWords[randPos]) {
      wordsFile.close();
      return word;
    }
    pos++;
  }

  // If the word specified can't be found for whatever reason above, this code will run as a backup and pick randomly from the words below
  const string errorWords[10] = {"diary", "bottle", "water", "packet", "tissue", "glasses", "watch", "sweet", "stamp", "postcard"};

  cout << "There was an error in the random word picking process. The word you are to guess may be below the minimum character count you inputted." << endl;

  return errorWords[(rand() % 10 + 1)];
}

// Creates a list of all of the indexes of words that reach the minimum word length. It also returns the index of the last element in the array
int possibleVaues(ifstream &wordsFile, int minimumLen, int possibleWords[]) {
  ifstream wordsLenFile("words_len.txt");
  int currWordLen, currArrayIndex = 0, currFileIndex = 0; // currFileIndex is the line of the file (-1) that the program is currently on
  
  // Goes through each word in the file and adds its index to possibleWords if its length is above the minimum length
  for (int i = 0; i < NUM_OF_WORDS_IN_FILE; i++) {
    wordsLenFile >> currWordLen;
    if (currWordLen >= minimumLen) {
      possibleWords[currArrayIndex] = currFileIndex;
      currArrayIndex++;
    }
    currFileIndex++;
  }

  wordsLenFile.close();
  return currArrayIndex; // Returns the length of the array possibleWords - 1
}

// Prints some relevant info to the user including the word (with unfound letters covered with underscores), the picture of the hanging man, and all of the previously guessed letters
void infoPrinter(string word, int wordLen, bool letterFound[], int numOfGuesses, char lettersGuessed[], int numOfTotalGuesses) {
  // Prints the words covered with underscores if the letter hasn't been found
  for (int i = 0; i < wordLen; i++) {
    if (letterFound[i])
      cout << word[i] << " ";
    else
      cout << "_ ";
  }
  cout << endl << endl;

  // Prints the "picture" of the hanging man
  switch (numOfGuesses) {
    case 0: // no wrong guesses
      cout << "/-----\n|\n|\n|\n|\n_________" << endl;
      break;
    case 1: // 1 wrong guess
      cout << "/-----\n|    |\n|    O\n|\n|\n_________" << endl;
      break;
    case 2:
      cout << "/-----\n|    |\n|    O\n|    |\n|\n_________" << endl;
      break;
    case 3:
      cout << "/-----\n|    |\n|    O\n|   \\|\n|\n_________" << endl;
      break;
    case 4:
      cout << "/-----\n|    |\n|    O\n|   \\|/\n|\n_________" << endl;
      break;
    case 5:
      cout << "/-----\n|    |\n|    O\n|   \\|/\n|   /\\\n_________" << endl;
      break;
  }

  // Outputs all of the previously guessed letters
  cout << endl << "Letters guessed: ";
  if (numOfTotalGuesses == 0)
    cout << endl;
  else if (numOfTotalGuesses == 1)
    cout << lettersGuessed[0] << endl;
  else if (numOfTotalGuesses == 2)
    cout << lettersGuessed[0] << " and " << lettersGuessed[1] << endl;
  else {
    for (int i = 0; i < (numOfTotalGuesses - 1); i++)
      cout << lettersGuessed[i] << ", ";
      cout << "and " << lettersGuessed[numOfTotalGuesses - 1] << endl;
  }

  return;
}

// Returns whether or not the word has been found as a boolean
bool wordFoundChecker(const bool letterFound[], int wordLen) {
  int numOfLettersFound = 0;

  // Finds the number of letters which have been found
  for (int i = 0; i < wordLen; i++) {
    if (letterFound[i])
      numOfLettersFound++;
  }

  return static_cast<bool>(numOfLettersFound == wordLen); // Returns if all of the letters have been found
}

// Prompts the user to a letter and returns the lowercase letter if it was valid
char inputLetter() {
  char inputtedChar; // Char inputted by the user
  int charValue; // Ascii int value of the char inputted

  cin >> inputtedChar;

  // Converts the char to its lowercase version
  charValue = tolower(inputtedChar);
  inputtedChar = static_cast<char>(charValue);

  // Checks if the char is a lowercase letter (a = 97; z = 122)
  if (inputtedChar < 97 || inputtedChar > 122) {
    cout << "Error, the inputted character was not a letter. Please enter a letter: ";
    return inputLetter(); // Promtps the user to enter a valid letter
  }

  return inputtedChar;
}

// Promtps the user to enter the minimum word length, checks that the input was valid, and returns it
int inputMinWordLen() {
  int minWordLen;
  
  cin >> minWordLen;

  // shortest word = 3 letters; longest = 14
  // 0 can be used for no minimum
  if (minWordLen == 0)
    return 0; // Retuns zero letters minimum
  else if (minWordLen < 3) { // Returns that the minimum length inputted was too short
    cout << "The minimum number of characters you entered was too low. Please enter 0 for no minimum or a number between 3 and 14: ";
    return inputMinWordLen();
  }
  else if (minWordLen > 14) { // Returns that the minimum length inputted was to long
    cout << "The minimum number of characters you entered was too high. Please enter 0 for no minimum or a number between 3 and 14: ";
    return inputMinWordLen();
  }
  else // Returns the inputted length since it was valid
    return minWordLen;

  // If the program somehow gets to here, this will prompt the user to enter the length again
  cout << "There was an error in processing your minimum word, please enter it again: ";
  return inputMinWordLen();
}
