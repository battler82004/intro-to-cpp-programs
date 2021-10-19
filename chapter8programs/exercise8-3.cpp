/*
  Title: Exercise 8-3 (Last Largest Index Finder)
  Description: This programs takes in 15 integers and outouts the array
  of integers, the position of the last largest index, and the value of
  that index.
  Author: James Taddei
  Date: 10/18/21
*/

#include <iostream>
using namespace std;

// Function prototypes
void listPrinter(const int listOfNum[], int listSize);
int lastLargestIndex(const int listOfNum[], int listSize);

int main() {
  // Variable declaration
  int listSize = 15, inNum, largestIndex;
  int listOfNum[listSize];

  // Program description
  cout << "This programs takes in 15 integers and outouts the array "
  << "of integers, the position of the last largest index, and the "
  << "value of that index." << endl;

  // Variable input
  for (int i = 0; i < listSize; i++) {
    cin >> inNum;
    listOfNum[i] = inNum;
  }

  // Outputs the array and finds the last largest index
  listPrinter(listOfNum, listSize);
  largestIndex = lastLargestIndex(listOfNum, listSize);

  // Outputs the index of the largest element
  cout << endl << "The position of the first occurrence of the " <<
  " largest element in list is: " << largestIndex << endl;

  // Outputs the value of the largest element
  cout << "The largest element in list is: " << listOfNum[largestIndex]
  << endl;

  return 0;
}

// Prints the list of nums out
void listPrinter(const int listOfNum[], int listSize) {
  for (int i = 0; i < listSize; i++) {
    cout << listOfNum[i] << " ";
  }
}

// Finds the index of that last occurance of the largest element
int lastLargestIndex(const int listOfNum[], int listSize) {
  int indexOfLargest = 0;

  for (int i = 0; i < listSize; i++) {
    if (listOfNum[i] >= listOfNum[indexOfLargest])
      indexOfLargest = i;
  }

  return indexOfLargest;
}
