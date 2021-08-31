/*
  Title: Exercise 2-13 (Final Price Calculator)
  Description: This program will find the final price of an item based on its original price, the percentage of the marked up price, and the sales tax rate.
  Author: James Taddei
  Date: 8/31/21
*/

#include <iostream>
using namespace std;

int main() {
    // Variable declaration
    double originalPrice, markUpPercent, salesTaxRate, sellingPrice, salesTax, finalPrice;

    // Program description
    cout << "This program will find the final price of an item based on its original price, the percentage of the marked up price, and tthe sales tax rate." << endl;

    // Variable input
    cout << "Enter the original price of the item: $";
    cin >> originalPrice;

    cout << endl << "Enter the percentage of the marked up price: ";
    cin >> markUpPercent;

    cout << endl << "Enter the sales tax rate: ";
    cin >> salesTaxRate;

    // Calculations
    sellingPrice = originalPrice * (1 + (markUpPercent / 100));
    salesTax = sellingPrice * (salesTaxRate / 100);
    finalPrice = sellingPrice + salesTax;

    // Final outputs
    cout << endl << "The original price of the item is $" << originalPrice << endl;
    cout << "The percentage of the markup was " << markUpPercent << "\%" << endl;
    cout << "The selling price of the item was $" << sellingPrice << endl;
    cout << "The sales tax rate was " << salesTaxRate << "\%" << endl;
    cout << "The sales tax was $" << salesTax << endl;
    cout << "The final price of the item was $" << finalPrice << endl;

    return 0;
}
