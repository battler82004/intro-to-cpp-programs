#include <iostream>
using namespace std;

int main()
{
    int candyBarsSold = 150;
    double price = 2.55, profit;
    
    profit = candyBarsSold * price;
    // "<<" is called the insertion operator, means it inserts something into the output
    cout << "The profist is : $" << profit << endl;
}
