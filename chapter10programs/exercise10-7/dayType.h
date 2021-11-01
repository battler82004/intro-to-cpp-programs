/*
  Description: This file declares dayType.
  Author: James Taddei
  Date: 11/1/21
*/

#ifndef H_dayType
#define H_dayType

#include <string>
using namespace std;

enum days{MON, TUE, WED, THUR, FRI, SAT, SUN};

class dayType {
    private:
        days currDay;
    public:
        void setCurrDay(days day);
        void printCurrDay();

        days getCurrDay();
        days findNextDay();
        days findPrevDay();
        void addXDays(int x);
};

#endif
