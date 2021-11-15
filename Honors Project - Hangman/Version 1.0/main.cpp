/*
  Title: Honors Project - Hangman
  Description: This program allows you to play a text-based version of hangman. To win, the user must find the word in 5 guesses.
  Author: James Taddei
  Credit: Source of words.txt - Xethron (https://github.com/Xethron/Hangman/blob/master/words.txt)
  Date: 11/13/21
*/

// Test more
// Class?
// Refactor
// Comment
// Hand-in?

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int NUM_OF_WORDS_IN_FILE = 872;

string randomWordPicker(int minimumWordLen);
int possibleVaues(ifstream &wordsFile, int minimumLen, int possibleWords[]);
void infoPrinter(string wordToGuess, int wordLen, bool letterFound[], int numOfGuesses, char lettersGuesed[], int numOfTotalGuesses);
bool wordFoundChecker(const bool letterFound[], int wordLen);
char inputLetter();
int inputMinWordLen();

int main() {
  int minimumWordLen, wordLen, numOfWrongGuesses = 0, numOfTotalGuesses;
  string wordToGuess;
  bool wordFound = false;
  char guessedLetter, playAgain;
  char lettersGuessed[26];

  srand(time(0));

  cout << "Minimum number of letters (up to 14, type 0 if you don't want a minimum): ";
  minimumWordLen = inputMinWordLen();

  wordToGuess = randomWordPicker(minimumWordLen);
  wordLen = wordToGuess.length();
  bool letterFound[wordLen];
  for (int i = 0; i < wordLen; i++)
    letterFound[i] = false;

  cout << endl << "The word is " << wordLen << " letters long" << endl;

  do {
    infoPrinter(wordToGuess, wordLen, letterFound, numOfWrongGuesses, lettersGuessed, numOfTotalGuesses);

    cout << "Guess a letter: ";
    guessedLetter = inputLetter();

    if (wordToGuess.find(guessedLetter) < wordLen) {
      for (int i = 0; i < wordLen; i++) {
        if (wordToGuess[i] == guessedLetter)
          letterFound[i] = true;
      }
      wordFound = wordFoundChecker(letterFound, wordLen);
    }
    else {
      numOfWrongGuesses++;
    }
    lettersGuessed[numOfTotalGuesses] = guessedLetter;
    numOfTotalGuesses++;
  } while (!wordFound && numOfWrongGuesses < 5);

  if (!wordFound) {
    infoPrinter(wordToGuess, wordLen, letterFound, numOfWrongGuesses, lettersGuessed, numOfTotalGuesses);

    cout << "You have failed to find the word with less than 5 wrong guesses. The word was '" << wordToGuess << "'. Better luck next time!" << endl;

    cout << "Would you like to play again (y/Y or n/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
      cout << endl << endl << endl;
      main();
    }
  }
  else {
    cout << endl << "Good job! You found the word with only " << numOfWrongGuesses << " wrong guesses." << endl;

    cout << endl << "Would you like to play again (y/Y or n/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
      cout << endl << endl << endl;
      main();
    }
  }
  
  return 0;
}

string randomWordPicker(int minimumLen) {
  ifstream wordsFile("words.txt");
  string word;
  static int possibleWords[NUM_OF_WORDS_IN_FILE] = {0};
  int maxIndex = possibleVaues(wordsFile, minimumLen, possibleWords);

  int randPos = (rand() % (maxIndex + 1)), pos = 0;

  while (getline(wordsFile, word)) {
    if (pos == possibleWords[randPos]) {
      wordsFile.close();
      return word;
    }
    pos++;
  }

  const string errorWords[10] = {"diary", "bottle", "water", "packet", "tissue", "glasses", "watch", "sweet", "stamp", "postcard"};

  cout << "There was an error in the random word picking process. The word you are to guess may be below the minimum character count you inputted." << endl;

  return errorWords[(rand() % 10 + 1)];
}

int possibleVaues(ifstream &wordsFile, int minimumLen, int possibleWords[]) {
  ifstream wordsLenFile("words_len.txt");
  int currWordLen, currArrayIndex = 0, currFileIndex = 0;
  

  for (int i = 0; i < NUM_OF_WORDS_IN_FILE; i++) {
    wordsLenFile >> currWordLen;
    if (currWordLen >= minimumLen) {
      possibleWords[currArrayIndex] = currFileIndex;
      currArrayIndex++;
    }
    currFileIndex++;
  }

  wordsLenFile.close();
  return currArrayIndex;
}

void infoPrinter(string word, int wordLen, bool letterFound[], int numOfGuesses, char lettersGuessed[], int numOfTotalGuesses) {

  for (int i = 0; i < wordLen; i++) { // Printing word
    if (letterFound[i])
      cout << word[i] << " ";
    else
      cout << "_ ";
  }
  cout << endl << endl;

  // Printing hanging picture
  switch (numOfGuesses) {
    case 0:
      cout << "/-----\n|\n|\n|\n|\n_________" << endl;
      break;
    case 1:
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

bool wordFoundChecker(const bool letterFound[], int wordLen) {
  int numOfLettersFound = 0;

  for (int i = 0; i < wordLen; i++) {
    if (letterFound[i])
      numOfLettersFound++;
  }

  return static_cast<bool>(numOfLettersFound == wordLen);
}

char inputLetter() {
  char inputtedChar;
  int charValue;

  cin >> inputtedChar;
  charValue = tolower(inputtedChar);
  inputtedChar = static_cast<char>(charValue);

  // a = 97; b = 122
  if (inputtedChar < 97 || inputtedChar > 122) {
    cout << "Error, the inputted character was not a letter. Please enter a letter: ";
    return inputLetter();
  }

  return inputtedChar;
}

int inputMinWordLen() {
  int minWordLen;
  
  cin >> minWordLen;

  // shortest word = 3 letters; longest = 14
  // 0 can be used for no minimum
  if (minWordLen == 0)
    return 0;
  else if (minWordLen < 3) {
    cout << "The minimum number of characters you entered was too low. Please enter 0 for no minimum or a number between 3 and 14: ";
    return inputMinWordLen();
  }
  else if (minWordLen > 14) {
    cout << "The minimum number of characters you entered was too high. Please enter 0 for no minimum or a number between 3 and 14: ";
    return inputMinWordLen();
  }
  else
    return minWordLen;

  cout << "There was an error in processing your minimum word, please enter it again: ";
  return inputMinWordLen();
}

/*
/-----
|    |
|    O
|   \|/
|   /\
_________
*/
