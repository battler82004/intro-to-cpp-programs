#include <iostream>
#include "extPersonType.h"
using namespace std;

// Prints all of the person's info
void extPersonType::print() const {
  personType::print(); // prints out the name
  cout << endl << "Date of Birth: ";
  dateOfBirth.printDate();
  cout << endl << "Phone Number: " << phoneNum << endl;
  cout << "Person Type: " << relation << endl;
  wholeAddress.print();
  cout << endl;
}

// Returns the person's relation
string extPersonType::getRelation() const {
  return relation;
}

// Returns the phone number of the person
string extPersonType::getPhoneNum() const {
  return phoneNum;
}

// Returns a date object holding the person's date
// of birth
dateType extPersonType::getDateOfBirth() const {
  return dateOfBirth;
}

// Returns an addressType ojbect holding all of the
// person's addres info
addressType extPersonType::getWholeAddress() const {
  return wholeAddress;
}

// Sets all of the variables to the inputted data values
void extPersonType::setExtPersonInfo(dateType birthday,
  addressType addressObject, string firstName,
  string lastName, string relationship,
  string phoneNumber) {
  
  setName(firstName, lastName);
  relation = relationship;
  phoneNum = phoneNumber;
  dateOfBirth = birthday;
  wholeAddress = addressObject;
}

// Default constructor
extPersonType::extPersonType(): personType() {
  relation = "";
  phoneNum = "";
}

// Constrcutor with default values (except for  date of
// birth and address)
extPersonType::extPersonType(dateType birthday,
  addressType addressObject, string firstName,
  string lastName, string relationship, string
  phoneNumber): personType(firstName, lastName) {

  relation = relationship;
  phoneNum = phoneNumber;
  dateOfBirth = birthday;
  wholeAddress = addressObject;
}
