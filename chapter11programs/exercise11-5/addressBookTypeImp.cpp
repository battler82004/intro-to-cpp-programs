#include <iostream>
#include <string>
#include "addressBookType.h"
using namespace std;

// Splits the inputted string on the first space
// and assigns them to the passed array
void split(string line, string subStrings[]) {
  subStrings[0] = line.substr(0, line.find(" "));
  // ^ is all of the string before the first space
  subStrings[1] = line.substr(line.find(" "),
    line.length()); // everything after the space

  // Removes the space that was used at the "split-point"
  string temp = subStrings[1];
  subStrings[1] = temp.erase(0, 1);
}

// Splits a string with 3 separated numbers and
// assigns them to the passed array
void splitTripleNum(string line, int dateNums[]) {
  // splitStrings1 ends up holding the first num and
  // the second two (in a single element). splitStrings2
  // holds the second and third num.

  string splitStrings1[2];
  string splitStrings2[2];

  split(line, splitStrings1);
  split(splitStrings1[1], splitStrings2);

  // Strings get converted to strings then stored
  // in inputted array
  dateNums[0] = stoi(splitStrings1[0]);
  dateNums[1] = stoi(splitStrings2[0]);
  dateNums[2] = stoi(splitStrings2[1]);
}

// Copies all of the data from inFile into the contacts
// array
void addressBookType::loadDataFromFile(ifstream
  &inFile) {
  // Variable creation
  int currFileIndex = 0, zipCodeNum;
  string names[2];
  int dateNums[3];
  string currLine, address, cityName, stateName,
    phoneNumber, relationship;
  dateType currDate;
  addressType currAddress;

  // Goes through each line in the inputted file and
  // adds all of the data into a contact in the array
  // contacts
  while (getline(inFile, currLine)) {
    if (currFileIndex == 7) {
      // Since relationship is last piece of data
      // of each contact, the program will create
      // a new contact with the data then reset
      // the counter
      relationship = currLine;

      currDate.setDate(dateNums[0], dateNums[1],
        dateNums[2]);
      currAddress.setAddress(address, cityName,
        stateName, zipCodeNum);
      contacts[filledIndex].setExtPersonInfo(
        currDate, currAddress, names[0], names[1],
        relationship, phoneNumber);
      filledIndex++;
      currFileIndex = 0; // keeps track of position
      // in current contact
      continue;
    }
    else if (currFileIndex == 6) {
      phoneNumber = currLine;
    }
    else if (currFileIndex == 5) {
      zipCodeNum = stoi(currLine);
    }
    else if (currFileIndex == 4) {
      stateName = currLine;
    }
    else if (currFileIndex == 3) {
      cityName = currLine;
    }
    else if (currFileIndex == 2) {
      address = currLine;
    }
    else if (currFileIndex == 1) {
      splitTripleNum(currLine, dateNums);
    }
    else {
      split(currLine, names);
    }
    currFileIndex++;
  }

  filledIndex--; // allows filledIndex to start at 0 so
  // that the contacts can be accessed correctly later
}

// Returns the contact at an index
extPersonType addressBookType::getContact(int index)
  const {

  return contacts[index];
}

// Swaps the contacts at indexes a and b of contacts array
void addressBookType::swap(int a, int b) {
  extPersonType temp = contacts[a];
  contacts[a] = contacts[b];
  contacts[b] = temp;
}

// Returns the index of the contact with a last name
// equal to the parameter. If no one with the name
// exists, -1 is returned
int addressBookType::searchByLastName(string
  lastName) const {
  // Goes through each contact until one with the
  // inputted last name is found
  for (int i = 0; i <= filledIndex; i++) {
    if (contacts[i].getLastName() == lastName)
      return i;
  }

  return -1; // returned if no contact has the inputted
  // last name
}

// Prints the names of all of the people with a birthday
// in the inputted month
void addressBookType::printBirthdaysInMonth(int month)
  const {
  // Goes through each contact and outputs their name
  // if their birth is on the inputted month
  for (int i = 0; i <= filledIndex; i++) {
    if (contacts[i].getDateOfBirth().getMonth() ==
      month) {
      cout << contacts[i].getFirstName() << " " <<
      contacts[i].getLastName() << endl;
    }
  }
}

// Prints the names of all of the people with last names
// between the two inputted names
void addressBookType::printNamesBetween(string name1,
  string name2) const {
  
  for (int i = 0; i <= filledIndex; i++) {
    if (contacts[i].getLastName() >= name1 && 
      contacts[i].getLastName() <= name2) {
      
      cout << contacts[i].getFirstName() << " " <<
      contacts[i].getLastName() << endl;
    }
  }
}

// Prints the names of all of the people with the
// inputted relationship type
void addressBookType::printRelationType(string
  relationship) const {

  for (int i = 0; i <= filledIndex; i++) {
    if (contacts[i].getRelation() == relationship) {
      cout << contacts[i].getFirstName() << " " <<
      contacts[i].getLastName() << endl;
    }
  }
}

// Outputs all of the data of all of the contacts in the
// array contacts
void addressBookType::print() const {
  for (int i = 0; i <= filledIndex; i++) {
    contacts[i].extPersonType::print();
    cout << endl;
  }
}

// Prints the info the contact at the inputted index of
// array contacts
void addressBookType::printContact(int index) const {
  contacts[index].extPersonType::print();
  cout << endl;
}

// Outputs all of the data in contacts into outFile
void addressBookType::saveToFile(ofstream &outFile) const {
  extPersonType person;

  for (int i = 0; i <= filledIndex; i++) {
    person = contacts[i];

    outFile << person.getFirstName() << " " <<
    person.getLastName() << endl;
    outFile << person.getDateOfBirth().getMonth() << " "
    << person.getDateOfBirth().getDay() << " " <<
    person.getDateOfBirth().getYear() << endl;

    addressType address = person.getWholeAddress();
    outFile << address.getStreetAddress() << endl;
    outFile << address.getCity() << endl <<
    address.getState() << endl << address.getZipCode();

    outFile << endl << person.getPhoneNum() << endl;
    outFile << person.getRelation() << endl;
  }
}

// Sorts all of the elements in contacts
void addressBookType::sort() {
  int newChanges = 1;
  string name1, name2;

  // So long as a change was made last time through,
  // the loop will swap out of place objects
  while (newChanges != 0) {
    newChanges = 0;
    for (int i = 0; i < filledIndex; i++) {
      name1 = contacts[i].getLastName();
      name2 = contacts[i+1].getLastName();
      if (name1 > name2) {
        swap(i, i+1);
        newChanges++;
      }
    }
  }
}
