#include <iostream>
using namespace std;

int main()
{
    int candyBarsSold;
    double price, profit;
    
    cout << "Enter candy bars sold: ";
    // ">>" is called the extraction operator, means it'll extract whatever is entered in the keyboard
    cin >> candyBarsSold;
    cout << "What is the price of a candy bar: ";
    cin >> price;
    
    profit = candyBarsSold * price;
    // "<<" is called the insertion operator, means it inserts something into the output
    // "endl" skips a line, I think like "\n"
    cout << "The profist is : $" << profit << endl;
}

// cin pauses the program to pause and waits for you to input something
