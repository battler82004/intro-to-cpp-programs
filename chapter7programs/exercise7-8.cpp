/*
  Title: Exercise 7-8 (Student Info Censoror)
  Description: This program takes in a student's name (first and last)
  Social Security number, userID, and password and returns the
  student's name, (censored) Social Security number, userID, and
  (censored) password.
  Author: James Taddei
  Date: 10/11/21
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  // Variable declaration
  string firstName, lastName, socialSecurityNum, userID, password;

  // Program description
  cout << "This program takes in a student's name (first and last) "
  << "Social Security number, userID, and password and returns the "
  << "student's name, (censored) Social Security number, userID, and "
  << "(censored) password." << endl;

  // Variable input
  cout << "Enter the students name, Social Security number, userID, "
  << "and password: ";
  cin >> firstName >> lastName >> socialSecurityNum >> userID >>
  password;

  // Final output
  cout << endl << firstName << " " << lastName << " xxxxxxxxx" <<
  " " << userID << " ";

  // Censors the password with x's
  for (int i = 0; i < password.length(); i++)
    password.at(i) = 'x';

  // Password output
  cout << password << endl;

  return 0;
}
