/*
  Description: This file declares romanType.
  Author: James Taddei
  Date: 11/1/21
*/

#include <string>
using namespace std;

class romanType {
  private:
    string romanNumeral; // Stores the roman numeral
    int arabicNum = 0; // standard int
  public:
    int charValue(char romanChar); // converts roman char to int
    void convertToInt(); // converts the numeral to an int
    void printArabicNum();
    void addToArabicNum(int addedNum); // arabicNum += addedNum

    void setRomanNumeral(string numeral);
};
