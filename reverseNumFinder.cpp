// Reverse Number Finder
// James Taddei
// 10/4/21

#include <iostream>
using namespace std;

int reverseDigit(int num);

int main() {
    int number;
    cout << "Enter an int: ";
    cin >> number;
    
    cout << endl << "The number " << number << " reversed = "
    << reverseDigit(number) << endl;

    return 0;
}

int reverseDigit(int num) {
    int reverseNum = 0;
    while(num > 0) {
        reverseNum *= 10;
        reverseNum += num % 10;
        num /= 10;
    }
    
    return reverseNum;
}