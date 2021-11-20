/*
  Title: Exercise 11-5 (Address Book)
  Description: This program works as an interactive
  address book with OOD in mind.
  Author: James Taddei
  Date: 11/19/21
*/

#include <iostream>
#include <string>
#include "addressBookType.h"
// Defines and declares all relevant classes
using namespace std;

int main() {
  // Variable declaration
  string fileName, name1, name2, relationship;
  int optionChoice, index, month;
  extPersonType person;

  // Program description
  cout << "This program works as an interactive" <<
  " address book with OOD in mind." << endl;

  // Input file prompt + variable creation
  cout << "Enter file name: "; // Ch11_Ex5Data.txt
  cin >> fileName;
  ifstream inBook(fileName);

  // Address book creation, loading data, and sorting
  addressBookType addressBook;
  addressBook.loadDataFromFile(inBook);
  addressBook.sort();

  while (true) {
    // Different option prompt
    cout << endl << endl << "Welcome to the address " <<
    "book program." << endl;
    cout << "Choose among the following options:" << endl;
    cout << "1: To see if a person is in the address book"
    << endl << "2: Print the information of a person" <<
    endl << "3: Print the names of person having birthday"
    << "in a particular month" << endl <<
    "4: Print the names of persons between two last names"
    << endl << "5: Print the names of persons having a "
    << "particular status" << endl <<
    "6: Print the address book" << endl << "7: Save data"
    << endl << "9: Terminate the program" << endl << endl;

    // Option input
    cin >> optionChoice;
    cout << endl;

    if (optionChoice == 1) {
      // Search for a person by last name

      // Last name input
      cout << "Enter the last name of the person: ";
      cin >> name2;
      cout << endl << endl;

      // Finds the index of the contact with the last
      // name and return -1 if it can't be found
      index = addressBook.searchByLastName(name2);
      if (index == -1) {
        cout << "Person not found." << endl;
        continue;
      }
      // Prints the contacts info
      addressBook.printContact(index);
    }
    else if (optionChoice == 2) {
      // Print the address, phone number, and date of
      // birth (if it exists) of a given person

      // Last name input
      cout << "Enter the person's last name: ";
      cin >> name2;
      cout << endl << endl;

      // Finds the index of the contact with the last
      // name and return -1 if it can't be found
      index = addressBook.searchByLastName(name2);
      if (index == -1) {
        cout << "Person not found." << endl;
        continue;
      }
      person = addressBook.getContact(index);

      // Outputs all of the person's relevant info
      person.personType::print();
      cout << endl << "Date of Birth: ";
      person.getDateOfBirth().printDate();
      cout << endl << "Phone Number: " <<
      person.getPhoneNum() << endl << "Person Type: " <<
      person.getRelation() << endl;
      person.getWholeAddress().print();
      cout << endl;
    }
    else if (optionChoice == 3) {
      // Print the names of the people whose birthdays
      // are in a given month
      
      // Month number input
      cout << "Enter the number of the month: ";
      cin >> month;
      cout << endl << endl;

      // Outputs the names of people who's birthday is
      // in the month inputted
      addressBook.printBirthdaysInMonth(month);
    }
    else if (optionChoice == 4) {
      // Print the names of all the people between two
      // last names

      // Last names input
      cout << "Last Names 1 and 2: ";
      cin >> name1 >> name2;
      cout << endl << endl;

      // Outputs the names of the people whose last
      // names are between the inputted two
      addressBook.printNamesBetween(name1, name2);
    }
    else if (optionChoice == 5) {
      // Depending on the user’s request, print the names
      // of all family members, friends, or business
      // associates

      // Input for the relation to the book owner
      cout << "Relation to Person: ";
      cin >> relationship;
      cout << endl << endl;

      // Outputs everyone who is of a certain relation
      // type to the book owner
      addressBook.printRelationType(relationship);
    }
    else if (optionChoice == 6) {
      // Print the entire address book
      addressBook.print();
    }
    else if (optionChoice == 7) {
      // Save the sorted address book to a file

      // File name input
      cout << "File Name: ";
      cin >> fileName;
      cout << endl;

      // Creates the file variable, stores the data, then
      // closes the file
      ofstream outFile(fileName);
      addressBook.saveToFile(outFile);
      outFile.close();
    }
    else if (optionChoice == 9) {
      break; // Ends the program
    }
    else {
      // Tells the user to enter a valid number
      cout << "Error, please a value between 1 and 9"
      << " (not 8 though). Restating options." << endl;
    }
  }

  inBook.close(); // Closes the input file

  return 0;
}
