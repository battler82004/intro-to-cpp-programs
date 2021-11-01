/*
  Description: This file defines the methods of dayType.
  Author: James Taddei
  Date: 11/1/21
*/

#include <iostream>
#include "dayType.h"
using namespace std;

void dayType::setCurrDay(days day) { // currDay assignment method
  currDay = day;
  return;
}

void dayType::printCurrDay() { // outputs currDay
  cout << "The current day is: " << currDay << endl;
  return;
}

days dayType::getCurrDay() { // returns currDay
  return currDay;
}

days dayType::findNextDay() { // returns the next day
  return static_cast<days>(currDay + 1);
}

days dayType::findPrevDay() { // returns the previous day
  return static_cast<days>(currDay - 1);
}

// returns the name of the day x days from curr day
void dayType::addXDays(int x) {
  int dayPos = static_cast<int>(currDay) + x;

  // these convert the int to the enum value
  if (dayPos == 0)
    cout << "Monday" << endl;
  else if (dayPos == 1)
    cout << "Tuesday" << endl;
  else if (dayPos == 2)
    cout << "Wednesday" << endl;
  else if (dayPos == 3)
    cout << "Thursday" << endl;
  else if (dayPos == 4)
    cout << "Friday" << endl;
  else if (dayPos == 5)
    cout << "Saturday" << endl;
  else
    cout << "Sunday" << endl;
}
