/*
  Title: Exercise 10-7 (Day Class)
  Description: This program takes in a day, stores it in a class with
  methods, outputs the current day, prints the next day, outputs the
  previou day, and outputs what x days from the current day will be.
  Author: James Taddei
  Date: 11/1/21
*/

#include <iostream>
#include "dayType.h"
using namespace std;

int main() {
  // Variable declaration
  dayType myDay;

  // Program description
  cout << "This program takes in a day, stores it in a class with " <<
  << "methods, outputs the current day, prints the next day, " <<
  "outputs the previou day, and outputs what x days from the " <<
  "current day will be." << endl;

  myDay.setCurrDay(static_cast<days>(0)); // objective 1
  myDay.printCurrDay(); // objective 2
  cout << "Curr day = " << myDay.getCurrDay() << endl; // objective 3
  cout << "Next day = " << myDay.findNextDay() << endl; // objective 4
  cout << "Previous day = " << myDay.findPrevDay() << endl;
  // ^ objective 5
  myDay.addXDays(4); // objective 6
  
  return 0;
}
